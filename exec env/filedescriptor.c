#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>


int main(void){

	int myfd = open("execvp.c", O_RDONLY);
	int myfd1 = open("fd.txt", O_RDONLY);
	
	printf("%d ", myfd);
	printf("%d\n", myfd1);
	
	close(myfd);
	close(myfd1);
}

