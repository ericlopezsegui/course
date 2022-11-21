#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd[2];
    
    char *p1[] = {"ls", NULL}; 
    char *p2[] = {"wc", "-l", NULL}; 

    if (pipe(fd)<0){
        perror("Error de creació del pipe fd[]");
        return EXIT_FAILURE;
        /* NOTREACHED */
    }

    pid_t pid1, pid2;

    switch (pid2 = fork()){
        case -1:
            perror("Error fork() - pid1");
            return EXIT_FAILURE;
        case 0:
            // Fill -> wc -l -> llegeix stdin i imprimeix a stdout
            // Tanquem stdin per llegir i redireccionem stdin per llegir de la pipe fd[0]
            dup2(fd[0],STDIN_FILENO);
            close(fd[1]);
            close(fd[0]);
            execvp(p2[0], p2);
            return EXIT_FAILURE;
    }

    switch (pid1 = fork()){
        case -1:
            perror("Error fork() - pid2");
            return EXIT_FAILURE;
        case 0:
            // Fill -> ls -> imprimeix a stdout
            // Tanquem stdout i redireccionem stdout a l'escriptura fd[1] de la pipe
            dup2(fd[1],STDOUT_FILENO);
            close(fd[0]);
            close(fd[1]);
            execvp(p1[0], p1);
            return EXIT_FAILURE;
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1,0,0);
    waitpid(pid2,0,0);
    return EXIT_SUCCESS;
}