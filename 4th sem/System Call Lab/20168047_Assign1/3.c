#include<stdio.h>
int main()
{
int i;
 
 	unsigned int pid1,pid2,pid3;
 	pid1=fork();
 	pid2=fork();
 	pid3=fork();
 	
 	printf("Hello , This is a process , its process id :%d its parent id is :%d\n", getpid(),getppid());
 	return 0;
 	
     
}
