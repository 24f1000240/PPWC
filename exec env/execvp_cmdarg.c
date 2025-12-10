//cmd line arg for execvp
//A program that creates a child process to run ls -l
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[1])
{
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        execvp(argv[1], &argv[1]);
    }
    else
    {
        wait(NULL);
        printf("child terminate\n");
    }

    return 0;
}

