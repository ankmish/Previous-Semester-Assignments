/*
Author - Ankit Mishra (20168047)
Date   - 17/01/18
Program- Illustration of pipe() , dup() , wait(), exec() system call to open a manual page
*/
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
int main(int arg,char *argv[])
{
	int fd[2];
	pipe(fd);
	printf("%s",argv[2]);
	int pid=fork();
	if(pid==0)
	{
		close(fd[1]);
		dup2(fd[0],0);
		char buffer[1000];
		read(fd[0],buffer,10);
		printf("%s",buffer);
		execlp("/usr/bin/gnome-terminal","gnome-terminal","--","man",buffer,NULL);	 // "--" to be used for latest version of gnome otherwise use "-x"

	}
	else
	{
		close(fd[0]);
		dup2(fd[1],1);
		printf("%s",argv[1]);
		write(fd[1],argv[2],10);
	}
}

