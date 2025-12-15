#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
int main() {
    sem_t s;
    int sem_value;
    sem_init(&s, 0, 10);
 
    sem_post(&s);

    sem_getvalue(&s, &sem_value);

    printf("Semaphore value: %d\n", sem_value);
    sem_wait(&s);

    sem_getvalue(&s, &sem_value);

    printf("Semaphore value: %d\n", sem_value);
    sem_destroy(&s);
    printf("Semaphore value: %d\n", sem_value);
    return 0;
}

