//output 1 2 3 4 parent prints 1 3 child print 2 4

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

int main() {
    pid_t pid;

    char *n1 = "/nam1";  //  process P
    char *n2 = "/nam2";  //  process Q

    sem_t *S;
    sem_t *T;

    S = sem_open(n1, O_CREAT, 0644, 0);
    T = sem_open(n2, O_CREAT, 0644, 1);

    pid = fork();

    if (pid == 0) { // Process P
        while (1) {
            // Entry section
            sem_wait(S);

            sleep(1);
            fprintf(stderr, "1");
            fprintf(stderr, "1");

            // remainder section
            sem_post(T);
        }
    } else { // Process Q (Parent Process)
        while (1) {
            // Entry section
            sem_wait(T);

            sleep(1);
            fprintf(stderr, "0");
            fprintf(stderr, "0");

            // remainder section
            sem_post(S);
        }
    }
    sem_close(S);
    sem_close(T);
    sem_unlink(n1);
    sem_unlink(n2);

    return 0;
}

