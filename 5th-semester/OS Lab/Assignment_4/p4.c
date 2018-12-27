#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,  char ** argv) 
{
    sigset_t intmask;      // set                                            // ------------------------------>>>>>>>>>>>>>
    // add SIGINT to set
    if((sigemptyset(&intmask) == -1) || (sigaddset(&intmask, SIGINT) == -1))   // --------------------->>>>>>>>>>>>>>>>>>>>>>>
    {
         perror("Failed to initialize the signal mask");
         return 1;
    }

	/*Lets do it*/
    while(1)
    {
        printf("Lets go to  BLOCK state\n");
        if(sigprocmask(SIG_BLOCK, &intmask, NULL) == -1)   //--------------------------->>>>>>>>>>>>>>>>>>>
            break;
        fprintf(stderr, "SIGINT signal blocked\n");
        sleep(5);

        printf("Leaving Blocking State & Entering UNBLOCK state\n");
         if (sigprocmask(SIG_UNBLOCK, &intmask, NULL) == -1)
            break;
        fprintf(stderr, "SIGINT signal unblocked\n");
        sleep(5);
    }
    perror("Failed to change signal mask");
    return 1;
}
