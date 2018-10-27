/*
NAME    -   ANKIT MISHRA
REG. NO.-   20168047
*/
#include<stdio.h> 
#include<time.h>
#include<stdlib.h>
void swap (long long int *a,long long int *b)
{
	long long int temp = *a;
	*a = *b;
	*b =  temp;
}
void maxHeapify(long long int a[],long long int i, long long int size)
{
	long long int lc,rc;
	lc = 2*i;
	rc = 2*i + 1;
	long long int maxi=i;
	if(lc < size && a[lc] > a[maxi])
		maxi = lc;
	if(rc < size && a[rc] > a[maxi])
		maxi = rc;
	
	if(maxi != i)
	{
		swap(&a[i],&a[maxi]);
		maxHeapify(a,maxi,size);
	}
}
void heapSort(long long int a[],long long int size)
{
	int i;
	for(i = size/2 ; i>=0; i--)
		maxHeapify(a,i,size);
	
	for (i=size-1; i>=0; i--)
        { 
        	swap(&a[0], &a[i]);
 		maxHeapify(a, 0, i);
    }
}
void printArray(long long int a[], long long int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("%lld ", a[i]);;
	printf("\n");
}
void main()
{
	FILE *fp=fopen("file2.txt", "r");
	long long int n,i,a[1000004];
	printf("\n Enter the number of elements :");
	
	scanf("%lld", &n);
	for(i=0;i<n;i++)
	    fscanf(fp,"%lld",&a[i]);
	fclose(fp);
	
	struct timeval start,end;
  	gettimeofday(&start,0);
  	heapSort(a , n);
  	gettimeofday(&end,0);
  	double diff=(end.tv_sec-start.tv_sec)*1e6+end.tv_usec-start.tv_usec;
  	diff/=1e6;
  	FILE *f=fopen("HeapSort_time_desc.txt","a");
  	fprintf(f,"%lld  %lf\n",n,diff);
  	fclose(f);
}
