#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    char msg[250]; int codret,pid;
    sprintf(msg,"Hola soc el pare.\n");
    write(1,msg,strlen(msg));
    if (fork()==0)
    {
        sprintf(msg,"Hola soc el fill.\n"); write(1,msg,strlen(msg));
        if (fork()==0)
        {
            sprintf(msg,"Hola soc el net.\n");write(1,msg,strlen(msg));
            sprintf(msg,"Adeu soc el net.\n");write(1,msg,strlen(msg));
            exit(1);
        }
        //pid=wait(&codret);
        sprintf(msg,"Adeu soc el fill.\n"); write(1,msg,strlen(msg));
        exit(1);
    }
    //pid=wait(&codret);
    sprintf(msg,"Adeu soc el pare.\n"); write(1,msg,strlen(msg));
    exit(1);
}