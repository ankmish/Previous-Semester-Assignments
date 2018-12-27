#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
void main(int argc,char **argv)
{
	pid_t pid;
	int fd[2];
	char str[100];
	int stat;
	while(1)
	{
		gets(str);
		int pp = pipe(fd);
		if(pp==-1) 
			perror("pipe nhi ho paega");
		pid = fork();
		if(pid<0)
			perror("Cant create child process");
		else if(pid==0)
		{
		    char msg[1000];
		    int num = read(fd[0],msg,strlen(str)+1);
		    msg[num]='\0';
		    printf("Message received by child :%s\n",msg); 
		    close(fd[0]);
		    gets(str);
		    write(fd[1],str,strlen(str)+1);
		    close(fd[1]);
		    exit(0);
		}
		else
		{
			write(fd[1],str,strlen(str)+1);
			wait(&stat);
			close(fd[1]);
			char buff[1000];
			int num = read(fd[0],buff,1000);
			buff[num]='\0';
			printf("Message recieved by parent : %s\n", buff);
			close(fd[0]);
		}
	}
}
