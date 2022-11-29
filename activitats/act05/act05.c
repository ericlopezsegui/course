#include "aux.h"

int num_players = 0;
int temp = 10;

pid_t temp;
pid_t *childs;

int main (int argc, char* argv[]){
    

    if (argc != 2){
        printf("Usage: %s <num_players>\n", argv[0]);
        return -1;
    }
    signal(SIGUSR1, SIG_IGN);   
    
    printf("Introdueix el numero de jugadors d'aquesta partida: ");
    scanf("%d", &num_players);

    switch(temp = fork()){
        case -1:
            perror("fork");
            return -1;
        case 0:
            printf("Temporitzador inicialitzat amb el proces: %d", getpid());
            char *argsv[] = {"./alarm", NULL};
            execv(argsv[0], argsv);
            exit(EXIT_SUCCESS);
        default:
            break;
    }
        

    childs = (pid_t*) malloc(num_players * sizeof(pid_t));

    for (int i = 0; i < num_players; i++){
        switch(childs[i] = fork()){
            case -1:
                perror("Error al crear el proces");
                exit(EXIT_FAILURE);
            case 0:
                printf("Soc el proces %d i el meu pare és %d\n", getpid(), getppid());
                char *argsv[] = {"./player", NULL};
                execv(argsv[0], argsv);
                exit(EXIT_SUCCESS);
            default:
                break;
        }
    }

    char pass[4];
    gen_password(pass);
    printf("La contrasenya és: %s\n", pass);

    return 0;
}

void sigHandler(int sig){
    if(sig == SIGUSR1){
        printf("S'ha acabat el temps");
    } 
}
