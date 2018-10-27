/*
AUTHOR    - ANKIT MISHRA
DATE      - 30/03/18       06:15 AM
PROGRAM 4 - Computing sqaure roots of integer from 0 to 99 using thread and perform given action as defined in the program 
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <stdlib.h> 
#include<math.h>
#include<pthread.h>

void * cal_sq(void * inf)  // function to calculate square root
{
	double *result = malloc(sizeof(double)*100); // array to hold the result 
	int i;
	for(i=0;i<100;i++)
		result[i] = sqrt((double)i);
	return (void *)result;	//	return the result
}
int main()
{
	double	* result;   // for result 
	pthread_t threadID;
	void  *status;
	int i;
	pthread_create(&threadID,NULL,cal_sq,NULL);
	pthread_join(threadID,&status);
	printf("RESULTS ARE AS FOLLOWS \n");   // short message by the main thread (as asked in the program)
	printf("     HERE YOU GO \n");
	result = (double *)status;
	for(i=0;i<100;i++)
		printf("\nsqrt(%d) = %lf",i,result[i]);
	free(result);	// to avoid memory leakage
	printf("\n");
	return 0;
}