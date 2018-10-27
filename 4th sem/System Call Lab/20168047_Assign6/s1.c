/*
	        ASSIGNMENT - 6 (BASIC SIGNAL PROGRAMMING)
NAME      - ANKIT MISHRA
REG. NO.  - 20168047
PROGRAM 1 - Handling different type of singal using single handler function 
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void SIGhandler(int sig)
{
	switch(sig)
	{
		case SIGINT:
			signal(SIGINT,SIG_IGN);  // first igonre the Signal 
			printf("Process Interrupted \n");
			break;
		case SIGHUP:
			signal(SIGHUP,SIG_IGN);
			printf("Controlling terminal hang up\nGive another try\n");
			break;
		case SIGTERM:
			signal(SIGTERM,SIG_IGN);
			printf("Process Termination\nTry again\n");
			break;
		case SIGQUIT:
			exit(0);    // Exit when Process Quiting Signal is Interrupted
			break;
	}
}
int main()
{
		//raise(SIGHUP);
		signal(SIGINT,SIGhandler);
		//kill(getpid(),SIGHUP);
		signal(SIGHUP,SIGhandler);
		signal(SIGTERM,SIGhandler);
		signal(SIGQUIT,SIGhandler);
		
		while(1)
			pause();
}

