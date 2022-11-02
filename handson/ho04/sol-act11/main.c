#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "pokemon.h"

void run_child(void);
void run_parent(void);

pid_t pid;
int st;

int
main(int argc, char *argv[])
{

   pid = fork();
    if (pid == -1) { perror("fork"); exit(EXIT_FAILURE);}
    else if (pid == 0) {  /* Code executed by child */          
        run_child();
   } else {   /* Code executed by parent */
        run_parent();
        exit(EXIT_SUCCESS);
    }
}

void run_child(){
        execl( "./pokedex", "pokedex", NULL);
        exit(-1);
}

void run_parent(){
    init_pokedex();     
    if ( waitpid(pid, &st, 0) >= 0 ) {
        if (WIFEXITED(st)) {
            show_pokemon(WEXITSTATUS(st));
        }
    };
}
