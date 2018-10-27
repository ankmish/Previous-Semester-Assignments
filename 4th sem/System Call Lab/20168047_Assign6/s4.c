/*
	        ASSIGNMENT - 6 (BASIC SIGNAL PROGRAMMING)
NAME      - ANKIT MISHRA
REG. NO.  - 20168047
PROGRAM 4 - Extension of Pro.1 using SIGCHILD
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/errno.h>
#include<sys/stat.h>
#include<signal.h>
void handler(int sig)
{
    signal(sig,SIG_IGN);
    switch(sig)
    {
        case SIGINT:
            printf("SIGINT signal generated\n");
            break;
        case SIGHUP:
            printf("SIGHUP signal generated\n");
            break;
        case SIGTERM:
            printf("SIGTERM signal generated\n");
            break;
        case SIGQUIT:
            printf("SIGQUIT signal generated \n now process will end...\n");
        exit(0);
        break;
    }
    signal(sig,handler);
}
int main()
{
    pid_t pid;
    pid=fork();
    if(pid<0)
    {
        perror("Error .. Child Process not Create !\n");
        exit(1);
    }
    if(pid==0)
    {
        
        while(1)
        {
            signal(SIGTERM,handler);
            signal(SIGHUP,handler);
            signal(SIGINT,handler);
            signal(SIGQUIT,handler);
        }
        exit(0);
    }
    else if(pid>0)
    {
        printf("Working  in parent process...\n");
        sleep(2);
        kill(pid,SIGTERM);
        sleep(2);
        kill(pid,SIGHUP);
        sleep(2);
        kill(pid,SIGQUIT);
        sleep(2);
        kill(pid,SIGINT);
        sleep(2);
    }
return 0;
}
