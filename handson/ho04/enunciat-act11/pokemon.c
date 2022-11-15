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
  
  char* buffer = malloc(151);
  char* info;
  
  if(!f) {
    perror("fopen");
    exit(1);
  }
  
  while(fgets(buffer, POKEMONS, f) != NULL){
    struct pokemon p;

    info = strtok(buffer, ",");
    int id = atoi(info);
    p.id = id;

    
    int c = 0;

    while(info){
      if (c == 0)
        p.id=atoi(info);
      if (c == 1)
        strcpy(p.name, info);
      if (c == 2 || c == 3)
        strcpy(p.type[c-2], info);
      if (c == 4)
        strcpy(p.total, info);    
      if (c == 5)
        strcpy(p.hp, info);    
      if (c == 6)
        strcpy(p.attack, info);
      if (c == 7)
        strcpy(p.defense, info);
      if (c == 8)
        strcpy(p.spAttack, info);
      if (c == 9)
        strcpy(p.spDefense, info);
      if (c == 10) 
        strcpy(p.speed, info);
      if (c == 11)
        strcpy(p.generation, info);
      if (c == 12)
        strcpy(p.legendary, info);
      c = c+1;
      info = strtok(NULL, ",");
    }
    pokedex[p.id-1] = p;
  }
  fclose(f);
  free (buffer);
}
