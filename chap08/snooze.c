#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sigint_handler(int sig) {
    return;
}

unsigned int snooze(unsigned int secs) {
    int slept = sleep(secs);
    printf("\nSlept for %d of %d secs.\n", secs - slept, secs);
    return slept;
}

int main() {
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        printf("signal error");
    }

    snooze(10);
    return 0;
}
