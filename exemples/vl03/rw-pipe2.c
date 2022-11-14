#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){ 
    int fd[2];
    pipe(fd);
    pid_t p1 = fork();  
    
    if (p1 == 0) {
        close(fd[0]);

        char * msg1 = malloc(5*sizeof(char));
        sprintf(msg1,"msg1");
        write(fd[1], msg1, strlen(msg1));
        free(msg1);

        sleep(3);

        char * msg2= malloc(5*sizeof(char));
        sprintf(msg2,"msg2");
        write(fd[1], msg2, strlen(msg2));
        free(msg2);

        // Nota1: L'efecte bloquejant de read, la línia (X) no tanca el pipe d'escriptura.
        //close(fd[1]); //(X)
        // Nota2: El while impedeix que el procés acabi i es tanquin els descriptors.
        while(1);
        
        exit(0);
}

close(fd[1]);
char * buf = malloc(5*sizeof(char));
while( read(fd[0],buf,sizeof(buf)) ){
    printf("I got a message! It was %s\n", buf);
}
printf("No more messages :(\n");
close(fd[0]);
free(buf);
return EXIT_SUCCESS;
}