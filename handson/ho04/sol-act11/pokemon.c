#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pokemon.h"

struct pokemon pokedex[POKEMONS];

void show_pokemon(int position){
    struct pokemon pokemon = pokedex[position];
    printf("\n============================= \n");
    printf("==  id: %d \n",  pokemon.id);
    printf("==  name: %s \n",  pokemon.name);
    printf("==  attack: %d \n",  pokemon.attack);
    printf("==  defense: %d \n",  pokemon.defense);
    printf("============================= \n");
}

void init_pokedex(void){

  FILE* f = fopen("./pokedex.csv", "r");
  if(!f) {
    perror("fopen");
    exit(1);
  }

  char *buf = malloc(POKEMONS);
  char *info;
  
  while (fgets(buf, POKEMONS, f) != NULL) {

    struct pokemon p; 
    int i = 0; // Represent the index of the columns
    info = strtok(buf, ","); 
    while(info){
        if (i==0)  p.id = atoi(info);
        if (i==1)  strcpy(p.name, info);
        if (i==2 || i==3)  strcpy(p.type[i-2], info);
        if (i==3)  p.total = atoi(info);
        if (i==4)   p.hp = atoi(info); 
        if (i==5)  p.attack = atoi(info);
        if (i==6)  p.defense = atoi(info);
        if (i==7)  p.spAttack = atoi(info);
        if (i==8)  p.spDefense = atoi(info);
        if (i==9)  p.speed = atoi(info);
        if (i==10)   p.generation = atoi(info);
        if (i==11)   p.legendary = atoi(info);
        i=i+1;
        info = strtok(NULL, ",");
    }
    pokedex[p.id -1]=p;
  }
  fclose(f);
  free(buf); 
}
