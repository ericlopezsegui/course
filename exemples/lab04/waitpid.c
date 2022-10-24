#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
    pid_t pid, w;
    int status;
    

   pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

   if (pid == 0) {            /* Code executed by child */
        printf("Child PID is %d\n", getpid());
        if (argc == 1)
            pause();                    /* Wait for signals */
        exit(atoi(argv[1]));

   } else {                    /* Code executed by parent */
        do {
            w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
            if (w == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }

           if (WIFEXITED(status)) {
                printf("exited, [%d] status=%d\n", pid, WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("killed by signal, [%d] -> %d\n", pid, WTERMSIG(status));
            } else if (WIFSTOPPED(status)) {
                printf("stopped by signal [%d] -> %d\n", pid, WSTOPSIG(status));
            } else if (WIFCONTINUED(status)) {
                printf("continued\n");
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        exit(EXIT_SUCCESS);
    }
}