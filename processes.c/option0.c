#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    int stat;
    pid_t WR;

    pid_t c1 = fork();

    if (c1 == 0) {
        printf("I am child 1 with pid %d and parent %d\n", getpid(), getppid());
        exit(0);
    }
    else {
        printf("I am parent %d\n", getpid());

        WR = waitpid(c1, &stat, 0);
        printf("Status returned = %d\n", stat);

        pid_t c2 = fork();

        if (c2 == 0) {
            printf("I am child 2 with pid %d and parent %d\n", getpid(), getppid());
            exit(1);
        }
    }

    return 0;
}

