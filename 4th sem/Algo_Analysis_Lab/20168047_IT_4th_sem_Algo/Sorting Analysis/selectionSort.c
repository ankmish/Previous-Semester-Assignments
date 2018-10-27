#include<time.h>
#include<stdio.h>
void main()
{
	int i,j,min,n,temp;
	scanf("%d", &n);
	
	
	FILE *fptr;
   	fptr = fopen("file2.txt", "r");
   	
   	
   	clock_t start,end;
   	double tt;
   	
   	long long int a[200005];
	
	
	for(i=0;i<n;i++)
   	{
   		fscanf(fptr,"%lld",&a[i]);
   	}
	
	
	start=clock();	
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
				min=j;
			else
				continue;
		}
		if(min!=i)
		{
			temp=a[min];
			a[min]=a[i];
			a[i]=temp;
			
		}
	}
	
	
	end=clock();
	
	tt=((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("Time taken  %lf", tt);
	printf("\n");
	//for(i=0;i<n;i++)
	//	printf("%d ", a[i]);
}
