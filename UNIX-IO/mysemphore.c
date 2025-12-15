#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

void main() {
    sem_t *s;

    s = sem_open("/mysemaphore", O_CREAT, S_IRUSR | S_IWUSR, 10);
    printf("%p\n", s);

    sem_close(s);
    sem_unlink("/mysemaphore");
    
}
