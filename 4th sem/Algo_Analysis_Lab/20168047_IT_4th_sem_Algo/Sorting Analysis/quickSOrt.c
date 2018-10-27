#include<stdio.h>
#include<time.h>
void swap(long long int* a, long long int* b)
{
    long long int t = *a;
    *a = *b;
    *b = t;
}
int partition (long long int arr[],long long int low,long long int high)
{
    long long int pivot = arr[high];    
    long long int i = (low - 1);  
 
    long long int j;
    for (j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;  
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(long long int arr[], long long int low,long long int high)
{
    if (low < high)
    {
        long long int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
	FILE *fp=fopen("file2.txt","r");
	long long int n;
	long long int arr[1000000];
	printf ("\n Enter the number of the terms :");
	scanf("%lld",&n);
	long long int i;
	for( i=0;i<n;i++)
		fscanf(fp,"%lld",&arr[i]);
	
	clock_t begin = clock();
	quickSort(arr, 0, n-1);
	clock_t end=clock();	
	double t= (double)(end - begin) / CLOCKS_PER_SEC;
	
	fclose(fp);
	FILE * fpt;
	fpt =fopen("quick_worst.dat", "a");   // best wala jo le rhe hai worst ho rha hai quick sort ke liye
	fprintf(fpt,"%lld %lf\n",n, t);     // avg. wala data apna best de rha hai since randomized 
						// dec. sort wala avg. de rha hai
    return 0;
}
