/*
	        ASSIGNMENT - 6 (BASIC SIGNAL PROGRAMMING)
NAME      - ANKIT MISHRA
REG. NO.  - 20168047
PROGRAM 2 -	Genearting Alarm signal 
*/
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
int i=5;   // loop iteration for 5 times
void message_sig(int sig)
{
	if(i<=0)
		exit(0);
	else
	{
		printf("Still Working on it--\n");
		i--;
		alarm(2);                        //now again set alarm
 		signal(SIGALRM, message_sig);   // generate message signal 
 	}
}
int main(void) 
{   
    signal(SIGALRM,message_sig);
    alarm(2);    // generating alarm after 2 sec.
    while (1) 
    	pause();   
    return 0;
}
