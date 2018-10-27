/*
Author   - ANKIT MISHRA
Reg. No. - 20168047
Problem  - ith Order Statistics (Based on Quick Sort)
*/

/*ASSUMPTION - All input elements should be distinct */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INF 999999999
void swap(long long int *a,long long int *b)
{
	long long int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	
}
/* Considers the last element as pivot and moves all smaller element to left of it and greater elements to right */
long long int partition(long long int arr[], long long int l, long long int r)
{
    long long int x = arr[r], i = l,j;
    for (j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
long long int ithOrder(long long int a[], long long int l,long long int r, long long int k)
{
	// check for if 'k' is smaller than the number of element
	if(k > 0 && k <= (r-l+1))
	{
		// partition the array to get the pivot element
		long long int pivot =  partition( a , l, r);
		// If pivot is same as k
		if(pivot - l== k-1)
			return a[pivot];
		// If pivot is more, recur for left subarray
		if( pivot - l > k - 1 )
			return ithOrder(a,l,pivot-1,k);
		else
			return ithOrder(a,pivot+1,r, k - pivot + l - 1 );
	}
	return INF;
}
void main()
{
	FILE * fp=fopen("file.txt", "r"); 
	long long int a[100000], n ,i,k;
	printf("\n Enter the number of the terms :");
	scanf("%lld", &n);
	printf("\n Enter the Value of 'k'th( smallest ) : ");
		scanf("%lld", &k);
	for(i = 0;i < n; i++)
		fscanf(fp,"%lld",&a[i]);
	fclose(fp);
	struct timeval start,end;
  	gettimeofday(&start,0);
	long long int res=ithOrder(a ,0,n-1,k);
	gettimeofday(&end,0);
  	double diff=(end.tv_sec-start.tv_sec)*1e6+end.tv_usec-start.tv_usec;
  	diff/=1e6;
  	FILE *f=fopen("4th_smallest_time.txt","a");
  	fprintf(f,"%lld  %lf\n",n,diff);
  	fclose(f);
}
