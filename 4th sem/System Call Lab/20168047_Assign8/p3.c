/*
AUTHOR    - ANKIT MISHRA
DATE      - 28/03/18    10.15 AM
PROGRAM 3 - To perform Matrix Multiplication using multiple threads
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
struct v 
{
   int i; // for row
   int j; // for column
};
void *multi(void *info);
int M,K,N;
int mat_A[100][100];   // matrix A
int mat_B[100][100];  // matrix B
int mat_C[100][100];   // resultant matrix C
int NUM_THREADS ;
int main(int argc, char *argv[]) 
{
    int i,j;
    printf("\n Try to enter the dimesions such that multiplication is possible .....");
    printf("\n Enter the dimensions of the 1st matrix (m*k) :");
    scanf("%d %d", &M,&K);
    printf("\n Enter the elements of the first matrix :");
    for(i=0;i<M;i++)
    {
        for(j=0;j<K;j++)
            scanf("%d", &mat_A[i][j]);
    }
    printf("\n Enter the dimensions of the 2nd matrix (k*n) :");
    scanf("%d %d", &K,&N);
    printf("\n Enter the elements of the 2nd matrix :");
    for(i=0;i<K;i++)
    {
        for(j=0;j<N;j++)
            scanf("%d", &mat_B[i][j]);
    }
    NUM_THREADS = M*N;  // no. of threads needed
   int  count = 0;
   for(i = 0; i < M; i++) 
   {
      for(j = 0; j < N; j++) 
      { 
         struct v *data = (struct v *) malloc(sizeof(struct v));  //Assign a row and column for each thread
         data->i = i;
         data->j = j;
         /* Now create the thread passing it data as a parameter */
         pthread_t tid;       //Thread ID
         pthread_attr_t attr; //Set of thread attributes
         pthread_attr_init(&attr);   //Get the default attributes
         //Create the thread
         pthread_create(&tid,&attr,multi,data);
         //Make sure the parent waits for all thread to complete
         pthread_join(tid, NULL);
         count++;
      }
   }
   //Print out the resulting matrix C
   for(i = 0; i < M; i++) 
   {
      for(j = 0; j < N; j++) 
         printf("%d ", mat_C[i][j]);
      printf("\n");
   }
}
void *multi(void *info)  // THREAD 
{
   struct v *data = info; // the structure that holds our data
   int n, sum = 0; //the counter and sum
   //Row multiplied by column
   for(n = 0; n< K; n++)
      sum += mat_A[data->i][n] * mat_B[n][data->j];
   //assign the sum to its coordinate
   mat_C[data->i][data->j] = sum;
   pthread_exit(0);
}