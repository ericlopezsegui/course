#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "pokemon.h"

pid_t pid;
int st;

void run_child(void);
void run_parent(void);

int
main(int argc, char *argv[])
{
    pid = fork();
    if (pid==-1){exit(-1);}
    else if (pid==0){  // Fill
        run_child();
    }
    else{ // Pare
        run_parent();
    }
}

void run_parent(){
    init_pokedex();
    if (waitpid(pid, &st, 0) >= 0){
            if ( WIFEXITED(st))
                show_pokemon(WEXITSTATUS(st));
    };
}

void run_child(){
    execl("./random","random", NULL);
    exit(-1);
}