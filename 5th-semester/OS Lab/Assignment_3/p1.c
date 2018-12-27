#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
void main(int argc,char ** argv)
{
	pid_t pid;
	pid = fork();
	int status;
	if(pid <0)
		perror("Cant create the child preocess");
	else if(pid==0)
	{
		printf("Executing the child process\n");
		printf("Child pid is %d and its parent pid is %d\n",getpid(),getppid());
		exit(14);
	}
	else
	{
	     wait(&status);
	     printf("Parent wait is over\n");
	     if(WIFEXITED(status)) {             //----------------------->>>>>>>>>>>>>>>>>>
	     	  printf("Exit status of child is :%d\n",WEXITSTATUS(status));
	     	   printf("Exit status of child is (in hexadec):%0X\n",WEXITSTATUS(status));
	    }
	}
}
