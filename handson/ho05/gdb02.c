#include <stdio.h>
#include <stdlib.h>
int main()
{
        int *p = malloc(3*sizeof(int));
        for(int i=0; i<3; i++){
            p[i]=1;
        }
        for(int i=0; i<3; i++){
           printf("%d\n", p[i]);
        }
        return 0;
}