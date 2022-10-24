#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int i = 11; //Allocated in data segment
int main(int argc, char* argv[]){
    int j= 22; // Allocated in stack
    int *z = malloc(sizeof(int)); // Allocated in heap

	pid_t pid;
	switch (pid=fork())
    {
    case 0:
        i *= 3; 
        j *= 3;
        *z=44;
        break;
    
    default:
        sleep(3);
        *z=55;
        break;
    }
    /* Both parent and child come here */  
    printf("PID=%ld %s data=%d stack=%d heap=%d\n", 
        (long) getpid(), (pid == 0) ? "(child) " : "(parent)", i, j, *z);
    return EXIT_SUCCESS;
}