/*
Author - Ankit Mishra (20168047)
Date   - 17/01/18
Program- Illustration of pipe() and dup2() system call
*/
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#define READ 0
#define WRITE 1
int main(int argc, char * argv[])
{
        int fd[2];
        int pid;
        if(pipe(fd) == -1) 
        {
          perror("Pipe failed");
          exit(1);
        }
	    pid=fork();
        if(pid == 0)           
        {
            close(1);               //closing stdout
            dup2(fd[1],1);         //replacing stdout with pipe write 
            close(fd[0]);         //closing pipe read
            close(fd[1]);
            char * const pro[] = { "/bin/ls", "-l", 0};
            execv(pro[0], pro);
            perror("execv of ls failed");
            exit(1);
        }
        else          
        {
            close(0);   
            dup2(fd[0],0);       //replacing stdin with pipe read
            close(fd[1]);       //closing pipe write
            close(fd[0]);
            char * const pro1[] = { "/usr/bin/sort", 0};
            execv(pro1[0], pro1);
            perror("execv of wc failed");
            exit(1);
        }
        close(fd[0]);
        close(fd[1]);
        wait(0);
        return 0;
}
