#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(long long int arr[], int l, int m, int r)
{
    long long int i, j, k;
    long long int n1 = m - l + 1;
    int n2 =  r - m;
 
 
    long long int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(long long  int arr[],long long int l,long long  int r)
{
    if (l < r)
    {
        
        long long int m = l+(r-l)/2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r);
    }
}
 
 
int main()
{
    	FILE *fp=fopen("file2.txt","r");
	
	printf("\n Enter no of elements :");
	long long int n;
	scanf("%lld",&n);
	long long int a[1000007];
	int i=0;
	for(i=0;i<n;i++)
		fscanf(fp,"%lld",&a[i]);
	
	clock_t begin = clock();
 	mergeSort(a, 0, n-1);	
	clock_t end=clock();	
	double t= (double)(end - begin) / CLOCKS_PER_SEC;
	
 	fclose(fp);
	FILE * fpt;
	fpt =fopen("merge_worst.dat", "a");
	fprintf(fpt,"%lld %lf\n",n, t);
    return 0;
}
