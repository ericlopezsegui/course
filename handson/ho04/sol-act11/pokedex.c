#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

int main(int argc, char** argv) {
    srand((unsigned int) getpid());   
    int r = rand()%151;  
    exit(r);
}