#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t fc, sc, tc;

    fc = fork();
    if (fc == 0) {
        sc = fork();
        if (sc == 0)
            printf("Process 1\n");
        else {
            wait(NULL);
            printf("Process 2\n");
        }
    } else {
        wait(NULL);
        tc = fork();
        if (tc == 0)
            printf("Process 3\n");
        else {
            wait(NULL);
            printf("Process 4\n");
        }
    }

    return 0;
}

