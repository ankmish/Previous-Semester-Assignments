/*
	        ASSIGNMENT - 6 (BASIC SIGNAL PROGRAMMING)
NAME      - ANKIT MISHRA
REG. NO.  - 20168047
PROGRAM 3 - Printing EXIT STATUS after child process is being killed
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>
void sigchild_handler(int sig)
{
	pid_t pid;
	pid = wait(NULL);
	printf("Pid %d exited.\n", pid);
}
int main(void)
{
	int stat;
	signal(SIGCHLD,sigchild_handler);
	if(!fork())
	{
		printf("Child pid is %d\n", getpid());
		exit(1);
	}
	else
	{
		printf("Parent pid is %d\n", getpid());
 		wait(&stat);
    	if (WIFEXITED(stat))
        	printf("Exit status of child process: %d\n", WEXITSTATUS(stat));
    }
	getchar();
	return 0;
}
