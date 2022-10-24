#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g = 0;
int main(int argc, char* argv[]){
	pid_t pid;
	int l = 1;
	printf("before fork\n");

	if ((pid = fork()) < 0) {
		err(EXIT_FAILURE, "fork error");
		/* NOTREACHED */
	} else if (pid == 0) {	/* child */
		g++;
		l++;
	} else {		/* parent */
		sleep(3);
		g--;
		l--;
	}

	printf("pid = %d, ppid = %d, g = %d, l = %d\n",
			getpid(), getppid(), g, l);
	return EXIT_SUCCESS;
}