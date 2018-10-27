/*
AUTHOR    - ANKIT MISHRA
DATE      - 28/03/18    09:50 AM
PROGRAM 2 - To create thread and set the priority of the each thread as defined by the user 
*/
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <stdlib.h> 

#define NUM_THREADS 5
   
pthread_t tid[6];
int arr[6]; 
 
void *hello(void *arg)
{
    int num;
    num = (int)arg;
    sleep(arr[num-1]-1);
    printf("Hey !! Its Thread No. %d of priority of %d \n", num,arr[num-1]);
    return (NULL);
}
int main()
{
  int i, retval,prior;
  for ( i = 0; i < NUM_THREADS; i++) 
  {
  	 printf("\n Enter the priority of the %dth thread :", i+1);
  	 scanf("%d",&arr[i]);
  }
  for ( i = 0; i < NUM_THREADS; i++) 
  {
     retval = pthread_create(&tid[i], NULL, (void*)hello,(void *)(i+1));
     if (retval != 0)
         perror("Error, could not create thread");
  }
  pthread_exit(NULL);
  printf("main() reporting that all %d threads have terminated\n", i);
  return (0);
}
