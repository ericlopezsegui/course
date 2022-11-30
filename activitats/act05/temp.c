#include "aux.h"

int main (int argc, char* argv[]){
    int time = atoi(argv[1]);
    if (time == 0){
        kill(getppid(), SIGUSR1);
        return -1;
    }

    while(time > 0){  
        sleep(1);
        time--;
    }
    kill(getppid(), SIGUSR1);

    return 0;
}

