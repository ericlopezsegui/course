#include "aux.h"

int main(int argc, char* argv[]){
    while (1){
        char pass[PASS_LEN];
        gen_password(pass);
        printf("La contrasenya és: %s\n", pass);
        sleep(1);
    }
}