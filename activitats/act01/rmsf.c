#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char current_dir[200];
    struct passwd pw = getpwuid(getuid());
    const char *userHome = pw->pw_dir;
    char trashdir[] = "/.trash/";

    getcwd(current_dir, sizeof(current_dir));
    strcat(userHome, trashdir)
    
    if (mkdir(userHome, 0777) == 0)
        printf("directori .trash creat.\n");

    for (int i=1; i<argc; i++) {
        char arg[100];
        char aux_arg[200];
        strcpy(arg, current_dir);
        strcat(arg, "/");
        strcat(arg, argv[i]);
        strcpy(aux_arg, userHome);
        strcat(aux_arg, argv[i]);
        rename(arg, aux arg);       
    }
    return 0;
}