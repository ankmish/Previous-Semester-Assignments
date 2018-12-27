#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(pid<0)
	 perror("Child process  creation fails");
	else if(pid==0)
	{
	    printf("\n Its child process is executing ...\n");
	}
	else
	{
        wait(NULL);
	   printf("\n Now I m going to execute as my child has executed");
	}
}
