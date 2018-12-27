#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
void main(int argc,char ** argv)
{
	pid_t pid;
	int fd[2];
	char str[100];
	gets(str);
	int pp = pipe(fd);
	if(pp==-1)
		perror("pipe nhi ho paega");
	pid = fork();
	if(pid<0)
		perror("Cant create child process");
	else if(pid==0)
	{
	    close(fd[1]);
	    char msg[1000];
	    int num = read(fd[0],msg,strlen(str)+1);
	    msg[num]='\0';
	    printf("Message received  :%s\n",msg); 
	}
	else
	{
		close(fd[0]);
		write(fd[1],str,strlen(str)+1);   //------------>>>> agar single char likhna hai to "&c"  rkhna  ,, here +1 in length needed
		wait(NULL);
	}
}

