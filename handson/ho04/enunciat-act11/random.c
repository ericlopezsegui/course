#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// El valor 151 s'ha d'agafar de la llibreria pokemon.h
int main(int argc, char** argv) {
    srand((unsigned int) getpid());   
    int r = rand()%151;  
    exit(r);
}