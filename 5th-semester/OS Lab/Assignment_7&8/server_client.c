#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<string.h>

sem_t allow;
sem_t mutex;

void *acquire(void * arg)
{
	int tid = (int) (intptr_t) arg;
	tid+=1;
	sem_wait(&mutex);

	sem_wait(&allow);                                            //----------------->>>>>>>>>>>>

	printf("\n Client %d is connected to the server....",tid);
	sem_post(&mutex);
	
	sleep(rand()%10);
	release(tid);

}
void  release(int num)
{
	printf("\n Client %d releases the Server ....",num);
	sem_post(&allow);                         //------------------------->>>>>>>>>>>>>>>>>>>>>>
}
void main(int argc,char ** argv)
{
	int n;
	int i;
	printf("\n Enter the number of client :");
	scanf("%d", &n);
	int maxi=6;         // maximum no. of connection available
	sem_init(&allow,0,maxi);  // semaphore that is initialised to maxi. no. of connection
	sem_init(&mutex,0,1);  // for mutual exclusion

	pthread_t thread[n];

	for(i=0;i<n;i++) {
		pthread_create(&thread[i],NULL,acquire,(void *) (intptr_t) i);   // Clients are acquiring ..
	}

	for(i=0;i<n;i++)
		pthread_join(thread[i],NULL);

	sem_destroy(&allow);
	sem_destroy(&mutex);

}
