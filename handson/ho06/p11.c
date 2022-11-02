#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
    int fd;
    fork();
    fd = open("out.txt",O_RDWR | O_CREAT);
    write(fd,"hola",5);
    exit(0);
}