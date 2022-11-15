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

    arguments[0] = token;
    int argIndex = 1;

    while(token != NULL) {
        arguments[argIndex] = token;
        token = strtok(NULL, delim);
        argIndex++;
    }

    arguments[argIndex] = NULL;
    
    char *path = malloc(5+strlen(arguments[0]));
    strcpy(path, "/bin/");
    strcat(path, arguments[0]);
    
    pid_t pid = fork();
    int status;
    if (pid == 0){
        execv(path, arguments);
        exit(0);
    } else {
        waitpid(pid, &status, WUNTRACED | WCONTINUED);
        return status;
    }
}

void ownCommands(char *cmd){
    int i, switchOwnArg = 0;
    char *listOwnCommands[3];

    listOwnCommands[0] = "exit";
    listOwnCommands[1] = "help";
    listOwnCommands[2] = "cd";

    if(strncmp(cmd, "cd", 2) == 0) {
        switchOwnArg = 3;
    } else if (strncmp(cmd, "help", 4) == 0) {
        switchOwnArg = 2;
    } else if(strncmp(cmd, "exit", 4) == 0) {
        switchOwnArg = 1;
    }

    switch (switchOwnArg){
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
    }
}

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