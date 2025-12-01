#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    pid_t chpd, retW;
    chpd = fork();
    int st;
    if (chpd < 0) {
        perror("fork failed");
        return 1;
    }

    if (chpd == 0) {
        printf("i am child with pid= %ld and parent PID = %ld\n", (long)getpid(), (long)getppid());
        sleep(10);
        printf("i am child with pid= %ld and parent PID = %ld\n", (long)getpid(), (long)getppid());
        printf("=========================================================\n");
    } 
    else {
    	printf("I am parent waiting\n");
        retW=wait(&st);
        printf("I am parent %ld\n", (long)getpid);
        printf("The details: \n status: %d retWait = %ld \n", st, (long)retW);
	}
    return 0;
}

