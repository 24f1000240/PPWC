#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    char *n1 = "/semp";
    char *n2 = "/semc";

    sem_t *S;   // parent semaphore
    sem_t *T;   // child semaphore

    S = sem_open(n1, O_CREAT, 0644, 1);
    T = sem_open(n2, O_CREAT, 0644, 0);
    pid = fork();
    if (pid == 0) {
        sem_wait(T);
        sleep(1);
        fprintf(stderr, "2 ");
        sem_post(S);

        sem_wait(T);
        sleep(1);
        fprintf(stderr, "4 ");
        sem_post(S);
    } else {
        sem_wait(S);
        sleep(1);	
        fprintf(stderr, "1 ");
        sem_post(T);

        sem_wait(S);
        sleep(1);
        fprintf(stderr, "3 ");
        sem_post(T);

        wait(NULL);
    }

    sem_close(S);
    sem_close(T);
    sem_unlink(n1);
    sem_unlink(n2);

    return 0;
}

