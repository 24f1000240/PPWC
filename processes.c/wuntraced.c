/* 
   Getting the status of stopsignal
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

    int stat = -1, i;
    pid_t WR;

    pid_t c1 = fork();

    if (c1 == 0) {

        for (i = 0; i < 25; i++) {
            printf("I am child(%d) and parent (%d) i = %d\n",
                   getpid(), getppid(), i);
        }

        sleep(30);
        exit(0);
    }
    else {

        WR = waitpid(c1, &stat, WUNTRACED);

        printf("I am parent %d\n", getpid());

        if (WIFSTOPPED(stat)) {
            printf("The stopped signal is : %d\n", WSTOPSIG(stat));
        }
    }

    sleep(80);

    return 0;
}

