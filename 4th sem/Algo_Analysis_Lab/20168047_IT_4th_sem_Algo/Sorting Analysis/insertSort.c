#include<stdio.h>
#include<time.h>
void insertSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}




void main()
{
	int i,j;
	int k;
	int n;
	scanf("%d", &n);
	
	FILE *fptr;
   	fptr = fopen("file2.txt", "r");
   	
   	
   	clock_t start,end;
   	double tt;
   	
   	int a[200005];
   	
   	for(i=0;i<n;i++)
   	{
   		 fscanf(fptr,"%lld",&a[i]);
   	}
		start=clock();
	
	
	insertSort(a,n);
	
	end=clock();
	
	tt=((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("Time taken  %lf", tt);
	printf("\n");
}
