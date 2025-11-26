#include<stdio.h>
#include<unistd.h>
int main(){
printf("Process id:%d\n",getpid());
printf("parent process id:%d\n",getppid());
while(1);
}
