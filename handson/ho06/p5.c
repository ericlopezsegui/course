#include <stdio.h>
#include <stdlib.h>
      
int main(void) 
{
    int y;   
    char *str; 
    y = 4;
    str = malloc(100*sizeof(char)); 
    str[0] = 'm';
    free(str);         
    return 0;
}