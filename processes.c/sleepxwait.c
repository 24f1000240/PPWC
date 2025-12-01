#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t cpid;
    int status = 0;

    cpid = fork();
    if (cpid == -1) {
        perror("fork failed");
        exit(-1);
    }

    if (cpid == 0) {
        printf("\nChild executing first, its pid = (%d)\n", getpid());
        sleep(20);
        printf("Child pid = %d\n", getpid());
        exit(1);
    } else {
        printf("\nParent executing before wait()\n");

        cpid = wait(NULL);  
        // cpid = wait(&status);

        printf("\nwait() in parent done\nParent pid = %d\n", getpid());
        printf("\ncpid returned is (%d)\n", cpid);
        printf("\nstatus is (%d)\n", status);
    }

    return 0;
}

