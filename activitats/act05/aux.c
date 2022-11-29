#include "aux.h"

void gen_password(char *code){
    unsigned int seed = (unsigned) getpid();
    srand(seed);

    int i;

    for (i = 0; i < PASS_LEN; i++){
        char c = (char) (rand() % 58 + 'A');
        if (c > 'Z' && c < 'a'){
            c += 6;
        }
        code[i] = c;
    }

    code[i] = '\0';
}