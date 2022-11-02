#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, n[1];
	n[0] = 9;
	free(n);
	printf("\n[%d] = %d ", 0, n[0]);
	return 0;
}