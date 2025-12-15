//read from myfile.txt write in myfile2.txt with O_creat and permission and O_append

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	char buf[100];
	int rbytes,wbytes;
	
	int fd=open("myfile.txt",O_RDWR);
	int fd1=open("myfile2.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	
	rbytes=read(fd,buf,20);
	wbytes=write(fd1,buf,rbytes);
	
	return 0;
}
