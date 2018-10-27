/*
NAME          - ANKIT MISHRA
REG. NO.      - 20168047
PROGRAM NO. 1 - Implementation od SIGCHILD using prev. Assignment problem and showing the use of sigaction() structure
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
int val;
// defintion of the handler
void handler(int sig)
{
	if(sig==SIGCHLD)    // signal received is for child
	{
		printf("Child Terminated with signal SIGCHLD \n");
		printf("return status of child is : %d \n",WEXITSTATUS(val));
	}
	else if(sig==SIGINT)
	{
		printf("Parent termination occur \n");
		exit(0);
	}
}
int main()
{
	struct sigaction sig;    // defining the structure of the sigaction()
	sig.sa_handler=handler;
	sig.sa_flags=0;
	pid_t pid;
	if(pid=fork()==0)               // child process
	{
		printf("Child Process is running \n");
		exit(val);
	}
	else
	{
		//parent process
		sigaction(SIGCHLD,&sig,NULL);
		sigaction(SIGINT,&sig,NULL);
		printf("Parent is waiting for the child to execute..\n");
		wait(&val);                                                // wait for  the child process to execute
		printf("Ctrl+C to termiante the parent \n");
		while(1);
	}
	return 0;
}
