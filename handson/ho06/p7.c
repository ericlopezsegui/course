#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main() { 
    char **names= malloc(sizeof(char*)*3);
    char *name = malloc(sizeof(char)*5);
    sprintf(name,"jordi",5);
    names[0] = name;

    sprintf(name,"pep",3);
    names[1] = name;

    sprintf(name,"manel",5);
    names[2] = name;

    for(int i=0; i<3; i++){
        printf("names[%d]= %s \n",i, names[i]);
    }

    free(names);
}