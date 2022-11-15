#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "pokemon.h"

pid_t pid;
int st;

int main(int argc, char *argv[]){
    pid = fork();
    if (pid == -1)
        exit(-1);
    else if (pid == 0){
        run_child();
    }
    else{
        run_parent();
    }
}

void run_parent(){
    init_pokedex();
    if (waitpid(pid, &st, 0) >= 0)
        show_pokemon(WEXITSTATUS(st));

    
}

void run_child(){
    execl("./random", "random", &st);
    exit(-1);
}