/*
Author - Ankit Mishra (20168047)
Date   - 17/01/18
Program- Illustration of pipe() system call
*/
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#define READ 0
#define WRITE 1
char message[100];
void main()
{
	int fd[2],BytesRead;
	if(pipe(fd)==-1)
	{
		perror("Pipe failed");
		exit(1);
	}
	char phrase[100];
	if(fork()>0)
	{
		close(fd[READ]);      // close the read file discriptor before using the writing file descriptor
		printf("\n What is the message ?? \n");
		gets(message);  
		write(fd[WRITE], message, strlen(message)+1);   // write the message in the parent process
		close(fd[READ]);
		wait(NULL);
	}
	else
	{
		close(fd[WRITE]);      // close the writing descriptor in the child process as it has to read only
		BytesRead=read(fd[READ], phrase, 100);     // read the meassge 
		printf("No. of Bytes read : %d\n Here Goes ur message \n %s \n", BytesRead, phrase);
		close(fd[READ]);
	}
}

