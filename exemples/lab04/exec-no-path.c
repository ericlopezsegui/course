#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
    pid_t pid;
    int status;

   pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

   if (pid == 0) {            /* Code executed by child */
        printf("(Before exec) - Child PID is %d\n", getpid());
       // execl( "ls", "ls", "-la", NULL);
	execl( "/usr/bin/ls", "ls", "-la", NULL);
        printf("(After exec) - Child PID is %d\n", getpid());
   } else {                    /* Code executed by parent */
         waitpid(pid, &status, WUNTRACED | WCONTINUED);
         if (WIFEXITED(status)) {
            printf("exited, [%d] status=%d\n", pid, WEXITSTATUS(status));
        }
        exit(EXIT_SUCCESS);
    }
}