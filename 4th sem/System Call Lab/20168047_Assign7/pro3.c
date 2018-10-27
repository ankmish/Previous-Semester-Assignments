/*
NAME          - ANKIT MISHRA
REG. NO.      - 20168047
PROGRAM NO. 3 - blocking the signal using sigaction() and signal_set
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
sigset_t set,waiting_mask;
void handler(int sig)
{
	int co=0;
switch(sig) {
	case SIGINT:
		// adding the SIGHUP and SIGABRT
		sigaddset(&set,SIGHUP);
		sigaddset(&set,SIGABRT);
		sigprocmask(SIG_BLOCK, &set, NULL);
		printf("SIGINT Signal Generated \n");
		sleep(6);   // make it sleep for few ms
		sigpending(&waiting_mask);                         // making signal in pending state
		printf("Blocked Signals are ::\n");
		if (sigismember(&waiting_mask, SIGINT))
	  {
				printf("SIGINT : ");
				co++;
		}
		if (sigismember(&waiting_mask, SIGHUP))
		{
				printf("SIGHUP : ");
				co++;
		}
		if (sigismember(&waiting_mask, SIGABRT))
		{
				printf("SIGABRT : ");
			  co++;
		}
		printf("\n No. of blocked signals : %d \n",co);   // count of total no. of blocked signal
		printf("Signal SIGTERM Over\n");
		sigprocmask(SIG_UNBLOCK, &set, NULL);
		sigemptyset(&set);
		break;
	case SIGQUIT:
		sigaddset(&set,SIGHUP);
		sigaddset(&set,SIGTERM);
		sigprocmask(SIG_BLOCK, &set, NULL);
	  printf("Signal SIGQUIT generated \n");
		sleep(6);
	  printf("Signal SIGQUIT Over\n");
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

		sigaction(SIGINT,&sig,NULL);
 		sigaction(SIGHUP,&sig,NULL);
		sigaction(SIGTERM,&sig,NULL);
		sigaction(SIGQUIT,&sig,NULL);
	  printf("pid : %d\n",getpid());
	  printf("Generating Signal SIGTERM and then attempt to generate the Signal SIGINT and SIGABRT  after specified time \n");
		while(1);

	  return 0;
}
