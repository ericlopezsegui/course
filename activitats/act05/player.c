#include "aux.h"

int main(int argc, char* argv[]){
    char *code = malloc(sizeof(char) * PASS_LEN);
    code = argv[1];

    while(1){
        char pass[PASS_LEN];
        gen_password(pass);

        if (strncmp(code, pass, PASS_LEN)){
            kill(getppid(), SIGUSR2);
        }
    }
    return 0;
}