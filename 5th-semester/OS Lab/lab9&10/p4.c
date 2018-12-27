#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include </usr/include/semaphore.h>

// for sleep
#include <unistd.h>

unsigned long int catalan(unsigned int n) 
{ 
	int i;
    // Base case 
    if (n <= 1) return 1; 
  
    // catalan(n) is sum of catalan(i)*catalan(n-i-1) 
    unsigned long int res = 0; 
    for ( i=0; i<n; i++) 
        res += catalan(i)*catalan(n-i-1); 
  
    return res; 
} 
  
unsigned long int  buf[100];
int count=0;
pthread_mutex_t mutex;

void producer(void *args){
	int x=(int *)args;
	unsigned long int result;
	pthread_mutex_lock(&mutex);
	printf("producing catalan number of->%d",x);
	printf("\n");
	result=catalan(x);
	
	count++;
	buf[count]=result;
	fflush(stdout);
	pthread_mutex_unlock(&mutex);


}

void consumer(void *args){
	int j;
	pthread_mutex_lock(&mutex);
	for(j=1;j<=count;j++){
		printf("catalan_number of %d->%lu\n",j,buf[j]);
	}
	pthread_mutex_unlock(&mutex);

}




int main(int argc,char* argv[]){
	int s=atoi(argv[1]);
	
	pthread_t p[s],c;

	int i;

	 pthread_mutex_init(&mutex, NULL);

	 for(i=1;i<=s;i++){
	 	sleep(2);
	 	pthread_create(&p[i],NULL,(void *)producer,(void *)i);
	 }
	 
	 pthread_create(&c,NULL,(void *)consumer,NULL);
	 pthread_exit(NULL);
}