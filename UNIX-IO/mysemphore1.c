#include<stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

void main() {
    char *n1 = "/mysemaphore1";
    sem_t *K;
    int val;

    K = sem_open(n1, O_CREAT | O_RDWR, 0644, 15);


    printf("%p\n", K);

    sem_getvalue(K, &val); 
    printf("%d\n", val);

    sem_post(K);
    sem_getvalue(K, &val);
    printf("%d\n", val);

    sem_wait(K);
    sem_getvalue(K, &val);
    printf("%d\n", val);
    
    //sem_unlink(n1);
}
