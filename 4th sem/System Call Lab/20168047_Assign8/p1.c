/*
AUTHOR    - ANKIT MISHRA
DATE      - 28/03/18    09:30 AM
PROGRAM 1 - To create 10 thread and print HELLO WORLD objective  
*/
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <stdlib.h> 

#define NUM_THREADS 10
   
pthread_t tid[12]; 
   
void *hello(void *arg)
{
    int num;
    num = (int)arg;
    int i;
    for(i=0;i<5;i++)
    {
    	printf("Hello World (Thread %d) \n", num);
    }
    return (NULL);
}
int main()
{
  int i, retval;
  for ( i = 0; i < NUM_THREADS; i++) 
  {
     retval = pthread_create(&tid[i], NULL, (void*)hello,(void *)(i+1));
       pthread_join(tid[i], NULL);
     if (retval != 0) 
     {
         perror("Error, could not create thread");
     }
  }
  printf("main() reporting that all %d threads have terminated\n", i);
  return (0);
}
