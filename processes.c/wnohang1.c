#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    int stat = -1, i;
    pid_t WR;

    pid_t c1 = fork();

    if (c1 == 0) {/* child */
        for (i = 0; i < 25; i++) {
            printf("I am child(%d) and parent (%d) i = %d\n",
                    getpid(), getppid(), i);
        }
        exit(0);
    }
    else {/* Parent */
        i = 0;

        while ((WR = waitpid(c1, &stat, WNOHANG)) != c1) {
            i = i + 1;
            printf("parent run %d --> I am parent %d\n", i, getpid());
            printf("parent Status returned = %d WR = %d\n", stat, WR);
        }

        printf("parent Status returned = %d WR = %d\n", stat, WR);
        printf("Status returned = %d\n", stat);
    }

    return 0;
}

