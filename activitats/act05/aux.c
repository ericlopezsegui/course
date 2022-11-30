#include "aux.h"

void gen_password(char *code){
    struct timeval tv;
    gettimeofday(&tv, NULL);

    unsigned int seed = (unsigned) getpid() * (unsigned) tv.tv_usec;
    srand(seed);

    int i;

    for (i = 0; i < PASS_LEN; i++){
        char c = (char) (rand() % 26 + 'A');
        code[i] = c;
    }

    code[i] = '\0';
}