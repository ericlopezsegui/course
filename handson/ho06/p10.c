#include <unistd.h>
#include <sys/wait.h>
int main() { 
    for ( int i = 0; i < 2; ++i) { 
      int pid = fork(); 
      write(1 , "*" , 1) ; 
      if (pid > 0) { 
        wait(NULL) ; 
        } 
    } 
}