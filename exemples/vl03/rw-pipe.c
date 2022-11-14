#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>

int main(int argc, char* argv[]){ 

    int fd[2];
    pid_t pidFill;
    
    if (pipe(fd) < 0) perror("pipe fd");

    pidFill = fork();

    if(pidFill == -1){  
        perror("fork");
        exit(1);
    } else if (pidFill == 0){ 
        /*El procés fill tanca la escriptura per la pipe*/
        close(fd[1]);
        /*El procés fill bloquejat fins rebré dades a la pipe*/
        char * msg = malloc(5*sizeof(char));
        printf("Procés fill %d -> esperant read(fd[0],%s,%ld)\n", getpid(),msg,sizeof(msg));
        ssize_t nbytes = read(fd[0], msg, sizeof(msg));

        if ( nbytes < 0) {
            perror("read fd[0]");
            exit(-1);
        } else{
            printf("Procés fill %d -> ha rebut una cadena a read(fd[0],%s,%ld)\n", getpid(),msg,sizeof(msg));
            free(msg);
            exit(0);
        }
    } else {
        /* El procés pare tanca la lectura per la pipe */
        close(fd[0]);
        char * msg = malloc(5*sizeof(char));
        sprintf(msg,"Hola");
        printf("Procés pare %d -> escrivint dades write(fd[1],%s,%ld)\n", getpid(),msg,sizeof(msg));
        ssize_t codret = write(fd[1], msg, sizeof(msg));
        if (codret == -1) perror("write fd[1]");
        wait(NULL);
        free(msg);
        return EXIT_SUCCESS;
    }
}