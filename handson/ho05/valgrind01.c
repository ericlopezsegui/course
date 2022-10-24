#include <stdio.h>
#include <stdlib.h>
int main()
{
        int **p = malloc(3*sizeof(int *));
        for(int i=0; i<3; i++){
           p[i] = malloc(2*sizeof(int));
        }
        p[0][0]=1;
        p[0][1]=3;
        p=NULL;
        return 0;
}