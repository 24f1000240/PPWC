#include<stdio.h>
#include<unistd.h>
int main(){
	fork() && fork();
	printf("pid: %ld Able\n", (long)getpid());
	while(1);
	return(0);
}
