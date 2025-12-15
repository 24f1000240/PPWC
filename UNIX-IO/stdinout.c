#include<stdio.h>
#include<unistd.h>
int main()
{
    char buf[100];
    int rbytes, wbytes;

    rbytes = read(0, buf, 20);   // STDIN_FILENO
    wbytes = write(1, buf, rbytes); // STDOUT_FILENO

    return 0;
}

