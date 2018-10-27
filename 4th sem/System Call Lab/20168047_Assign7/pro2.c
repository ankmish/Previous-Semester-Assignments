/*
NAME          - ANKIT MISHRA
REG. NO.      - 20168047
PROGRAM NO. 2 - Masking of a signal while signal handler is busy in processing the signal
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
sigset_t set;
// defintion of the handler
void handler(int sig)
{
	switch(sig)
	{
		case SIGINT:
			printf(" SIGINT Signal Generated \n");
			sleep(6);
			printf("SIGINT Signal Over \n");
			break;
	  case SIGHUP:
			printf(" SIGHUP Signal Generated \n");
			sleep(6);
			printf("SIGHUP Signal Over\n");
			break;
	  case SIGTERM:
			printf(" SIGTERM Signal Generated \n");
			sleep(6);
			printf("SIGTERM Signal Over \n");
			break;
		case SIGQUIT:
			printf("SIGQUIT Signal Generated \n");
			sleep(6);
			printf("SIGQUIT Signal Over \n");
			exit(0);
			break;
	}
}
int main()
{
			struct sigaction sig;
			sig.sa_handler=handler;
			sig.sa_flags=0;
			sigemptyset(&set);

			// adding the differenr signal to the strcuture
			sigaddset(&set,SIGINT);
			sigaddset(&set,SIGHUP);
			sigaddset(&set,SIGTERM);
			sigaddset(&set,SIGQUIT);
			sig.sa_mask=set;

 			pid_t pid;
		// creating child and parent process
		 if( ( pid=fork() ) == 0)
		 {
						//child process
					sigaction(SIGINT,&sig,NULL);
		   		sigaction(SIGHUP,&sig,NULL);
					sigaction(SIGTERM,&sig,NULL);
					sigaction(SIGQUIT,&sig,NULL);
					while(1);
	 	}
		else
		{
			//parent process
				 printf("pid : %d \n",pid);
				printf("Let's Generate the signal ... \n");
		   	while(1);
		}
		return 0;
}
