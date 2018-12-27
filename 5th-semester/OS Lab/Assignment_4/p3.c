#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<malloc.h>
volatile sig_atomic_t stop; // important to get out  of inifinte loop ....   // -------------------->>>>>>>>>>>>>>>>>
void user_handler(int sig)
{
    printf("\n Caught the signal : %d",sig);
}
void user_hand(int sig)
{
    printf("\n This signal is to stop the process : %d",sig);
    stop = 1;
}
void main(int argc,char ** argv)
{
    signal(SIGINT,user_handler);
    signal(SIGTSTP,user_hand);
    while(!stop)
    {
        printf("Hey !! Its  running ...\n");
        sleep(1);
    }
}
