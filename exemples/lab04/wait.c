#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int status;		
pid_t child_pid;

int main(int argc, char* argv[]){
	pid_t pid;
	if ((pid = fork()) < 0) {
		err(EXIT_FAILURE, "fork error");
	} else if (pid == 0) {	
		printf("pid = %d, ppid = %d, -> %s\n", getpid(), getppid(), "My name is Rhaenyra daughter of King Viserys I");
            exit(0);
	} else {
		child_pid = wait(&status);
        printf("pid = %d, -> %s (%d)\n",getpid(), "My name is King Viserys and I known that Rhaenyra finished her job.",child_pid);
	}
    child_pid = wait(&status);
    printf("pid = %d, -> %s (%d)\n", getpid(), "My name is King Viserys and I am sad... I have no more child working... :(", child_pid);

	return EXIT_SUCCESS;
}