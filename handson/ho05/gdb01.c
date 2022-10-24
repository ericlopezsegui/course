#include <stdio.h>
int main()
{
        int i = 2;
        printf("%d\n", i);
        int *p = NULL;
        *p = 0;
        printf("%d\n", *p);
        return 0;
}