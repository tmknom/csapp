#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    printf("Command-line arguments:\n");
    for (int i = 0; *argv != NULL; ++i) {
        printf("    argv[%d]: %s\n", i, *argv);
        argv++;
    }

    printf("\nEnvironment variables:\n");
    for (int i = 0; *envp != NULL; ++i) {
        printf("    envp[%d]: %s\n", i, *envp);
        envp++;
    }

    return 0;
}
