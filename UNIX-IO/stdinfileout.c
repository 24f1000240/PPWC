#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
    char buf[100];
    int rbytes, wbytes, fd;
    fd=open("myfile.txt", O_WRONLY);
    rbytes = read(0, buf, 20);   // STDIN_FILENO
    wbytes = write(fd, buf, rbytes); 

    return 0;
}

