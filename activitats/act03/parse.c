#include "parse.h"
#include "log.h"

void parseLine(char *line){
    char *delim = ";\n\0";
    char *rest = line;

    char *token;

    while(token = strtok_r(rest, delim, &rest)){
        parseCommand(token);
    }
}
int parseCommand(char *command) {


    if (parseErrors(command) == 1) {
        return 0;
    }

    ownCommands(command);

    char *delim = " ";

    char *arguments[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    char *token = strtok(command, delim);

    // @Jordi: Compte! Esteu copiant adreçes!
    arguments[0] = token;

    // @Jordi: Compte! Si introduim un comanda buida el programa petarà!
    if ( token != NULL ){
        char *path = malloc(strlen(token));
        //strcpy(path, "/bin/");
        strcpy(path, token);

        int argIndex = 0;
        while(token != NULL) {
            // arguments[argIndex] = token;
            // Necessitem que s'assgni memoria a la pos argIndex
            arguments[argIndex] = strdup(token);
            token = strtok(NULL, delim);
            argIndex++;
        }
        
        // Not required
        //arguments[argIndex] = NULL;
    
        // @Jordi: Aquest troç es pot definir en una funció
        pid_t pid = fork();
        int status;
        if (pid == 0){
            execvp(path, arguments);
            exit(0);
        } else {
            waitpid(pid, &status, WUNTRACED | WCONTINUED);
            return status;
        }
    }
}

void ownCommands(char *cmd){
    //int i, switchOwnArg = 0;

    // @Jordi: Not used!!!!
    /*char *listOwnCommands[3];
    listOwnCommands[0] = "exit";
    listOwnCommands[1] = "help";
    listOwnCommands[2] = "cd";*/

    // OMG: Podem evitar el switch no....

    if(strncmp(cmd, "cd", 2) == 0) {
        //switchOwnArg = 3;
        cdCommand(cmd); 
    } else if (strncmp(cmd, "help", 4) == 0) {
        //switchOwnArg = 2;
        openHelp();
    } else if(strncmp(cmd, "exit", 4) == 0) {
        //switchOwnArg = 1;
        exit(0);
    }

   /* switch (switchOwnArg){
        case 1:
            exit(0);
        case 2:
            openHelp();
            break;
        case 3:
            cdCommand(cmd); 
            break;
        default:
            break;
    }*/
}

// No demanada...
void cdCommand(char *cmd){
    char *token = strtok(cmd, " ");
    token = strtok(NULL, " ");
    chdir(token);
    return;
}

void openHelp(){
    puts("#### GTIDIC - UDL - OSSH #################################\n"
        "#                                                        #\n"   
        "# Type program names and arguments, and hit enter.       #\n"
        "# Use the man command for information on other programs. #\n"
        "#                                                        #\n"
        "##########################################################\n");
    return;
}

int parseErrors(char *command){
    for (int i = 0; i < strlen(command); i++){
        if (command[i] == '|' || command[i] == '<' || command[i] == '>' || command[i] == '&'){
            log_error("Error: command has [ | < > & ]");
            return 1;
        }
    }
    return 0;
}
