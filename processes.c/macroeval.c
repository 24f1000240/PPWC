#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t childpid, pid;
    int status;
    pid = fork();
    if (pid == 0) {
    	printf("i am child with pid= %ld and parent PID = %ld\n", (long)getpid(), (long)getppid());
        sleep(100);
        printf("Child Part Executed\n");
        exit(0);
        
    }
    else {
    	printf("I am parent %ld\n", (long)getpid);
        childpid = wait(&status);

        if (childpid == -1) {
            perror("Failed to wait for child\n");
        }
        else if (WIFEXITED(status) && !WEXITSTATUS(status)) {
            printf("Child %ld terminated normally\n", (long)childpid);
        }
        else if (WIFEXITED(status)) {
            printf("Child %ld terminated with return status %d\n",
                   (long)childpid, WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status)) {
            printf("Child %ld terminated due to uncaught signal %d\n",
                   (long)childpid, WTERMSIG(status));
        }
    }

    return 0;
}

