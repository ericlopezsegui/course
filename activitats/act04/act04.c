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
    // grep $whoami < /etc/passwd >> user.txt
    // 2 processos fills 
    //   -> 1 Fill executara grep
    //   -> 1 Fill executara whoami

    // @Jordi: Per una pipe únicament calen 2 descriptor 
    int fd[2]; //int fd[3];
    
    // @Jordi: cat no es necessari -> no ho demana l'enunciat
    //char *p1[] = {"cat", "/etc/passwd", NULL};

    char *p2[] = {"grep", "root", NULL};
    char *p3[] = {"$(whoami)", NULL};
    
    // @Jordi: Millor obrir únicament el fitxer en el procés que ho necessiti.
    //FILE *f = fopen("user.txt", "a");;

    if (pipe(fd)<0){
        perror("Error de creació del pipe fd[]");
        return EXIT_FAILURE;
        /* NOTREACHED */
    }

    pid_t pid1, pid2;

    switch (pid1 = fork()) {
    case -1:
        perror("Error de fork()");
        return EXIT_FAILURE;
        /* NOTREACHED */
    case 0:

        close(fd[1]);

        // GREP per defecte llegeix de stdin
        // GREP ha de llegir de /etc/passwd
        FILE *input_file = fopen("/etc/passwd", "r");
        dup2(fileno(input_file), STDIN_FILENO);

        // GREP per defecte escriu a stdout
        // GREP ha d'escriure a users.txt
        FILE *output_file = fopen("user.txt", "a");
        dup2(fileno(output_file), STDOUT_FILENO);
        
        // Ara si executeu filtra l'usuari root
        // Aquest usuari l'heu de llegir de la pipe
        // read(fd[0])....
        // El valor que llegiu l'heu de posar a p2[1]
        close(fd[0]);
        
        execvp(p2[0], p2);
        perror("Error de execvp()");
        return EXIT_FAILURE;
        /* NOTREACHED */
    }

    /* NO CAL
    switch (pid2 = fork()){
        case -1:
            perror("Error fork() - pid2");
            return EXIT_FAILURE;
        case 0:
            // Fill -> cat /etc/passwd -> llegeix stdin i imprimeix a stdout
            // Tanquem stdin per llegir i redireccionem stdin per llegir de la pipe fd[0]
            dup2(fd[0],STDIN_FILENO);
            close(fd[1]);
            close(fd[0]);
            execvp(p1[0], p1);
            return EXIT_FAILURE;
    }*/

    switch (pid2 = fork()){
        case -1:
            perror("Error fork() - pid1");
            return EXIT_FAILURE;
        case 0:
            // @Jordi: La comanda whoami escriu per defecte a stdout
            // @Jordi: Ara escriu a la pipe fd[1]
            dup2(fd[1],STDOUT_FILENO);
            //strcat(p2[1], p3[0]); 
            close(fd[0]);
            close(fd[1]);
            execvp(p2[0], p2);
            return EXIT_FAILURE;
    } 
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1,0,0);
    waitpid(pid2,0,0);
    return EXIT_SUCCESS;
}
