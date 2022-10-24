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
		printf("%s\n", "My name is Rhaenyra daughter of King Viserys I.");
		printf("%s\n", "My name is Rhaenyra daughter of King Viserys I.");
		printf("%s\n", "My name is Rhaenyra daughter of King Viserys I.");
	} else {
        printf("%s\n","My name is King Viserys and I do not known that Rhaenyra finished her job.");
		printf("%s\n","My name is King Viserys and I do not known that Rhaenyra finished her job.");
		printf("%s\n","My name is King Viserys and I do not known that Rhaenyra finished her job.");
	}
    child_pid = wait(&status);
	return EXIT_SUCCESS;
}