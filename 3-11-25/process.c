#include<stdio.h>
#include<unistd.h>
int main(){
  int x=0;
  printf("x= %d The process id of the process is %ld\n",x,(long)getpid());
  fork();
  x = 1;
  
  printf("x= %d The process id of the process is %ld  and my parent is %ld\n",x,(long)getpid(),(long)getpid());
  return 0;


}
