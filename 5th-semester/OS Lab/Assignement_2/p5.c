#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
void  main()
{
     pid_t  pid;
     int    i;
     int stat;
     int pp = fork();
    if(pp==0)
    {
       sleep(2);
       printf("\n Child wakes up after 2 sec.");
       exit(1);
    } 
    if(pp>0)
    {
	  wait(NULL);
       printf("\n Parent wait over !!!!");
    }
}
