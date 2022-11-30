#include "aux.h"

void sigHandler(int);

int num_players;
char *temps;
time_t start_time;
time_t end_time;

pid_t temp;
pid_t *childs;

int main (int argc, char* argv[]){
    
    if (argc != 4){
        printf("Usage: %s <num args>\n", argv[0]);
        return -1;
    }

    temps = argv[1];

    num_players = atoi(argv[2]);

    char *pass = malloc(sizeof(char) * PASS_LEN);
    pass = argv[3];

    signal(SIGUSR1, sigHandler);  

    printf("Inici del Room Escape [%d] (%s segons)\n", getpid(), temps);

    printf("--- Entren %d jugadors a la sala\n", num_players);

    printf("--- La contrasenya a endevinar és: %s\n", pass);
     

    childs = (pid_t*) malloc((unsigned) num_players * sizeof(pid_t));

        switch(temp = fork()){
        case -1:
            perror("fork");
            return -1;
        case 0: ;
            char *argsv[] = {"./temp", temps, NULL};
            execv(argsv[0], argsv);
            exit(EXIT_SUCCESS);
        default:
            start_time = time(NULL);
            localtime(&start_time);
            break;
    }

    
    for (int i = 0; i < num_players; i++){
        switch(childs[i] = fork()){
            case -1:
                perror("Error al crear el proces");
                exit(EXIT_FAILURE);
            case 0:
                printf(BLUE" EscapeRoom[%d] ha entrat el jugador[%d]\n"RESET, getppid(), getpid());
                char *argsv[] = {"./player", NULL};
                execv(argsv[0], argsv);
                exit(EXIT_SUCCESS);
            default:
                break;
        }
    }

    pause();
    return 0;
}


void sigHandler(int sig){
    if(sig == SIGUSR1){
        printf(RED"***********DING DONG\n"RESET);
        for (int i = 0; i < num_players; i++){
            printf(RED" El jugador [%d] ha quedat atrapat i surt del Escape Room [%d]\n"RESET, childs[i], getpid());
            kill(childs[i], SIGKILL);
        }
        printf(" Els jugadors han perdut la partida. Fins aviat.\n");
        exit(EXIT_SUCCESS);
    } 
    else if(sig == SIGUSR2){
        end_time = time(NULL);
        localtime(&end_time);
        for (int i = 0; i < num_players; i++){
            printf(GREEN" El jugador [%d] ha escapat i surt del Escape Room [%d]\n"RESET, childs[i], getpid());
            kill(childs[i], SIGKILL);
        }
        printf(" Els jugadors han guanyat la partidaen %d segons.\n", (int) difftime(end_time, start_time));
        exit(EXIT_SUCCESS);
    }
    exit(0);
}
