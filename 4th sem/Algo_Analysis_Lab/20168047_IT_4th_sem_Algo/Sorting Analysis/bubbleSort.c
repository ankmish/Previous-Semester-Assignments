#include<time.h>
#include<stdio.h>
void main()
{
	int i,j;
	int n,temp;
	scanf("%d", &n);
	
	
	
	FILE *fptr;
   	fptr = fopen("file1.txt", "r");
   	
   	
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
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		double t= (double)(end - begin) / CLOCKS_PER_SEC;
	FILE * fpt;}
	}
	
	end=clock();
	
	tt=((double)(end-start))/CLOCKS_PER_SEC;
	

	fclose(fptr);
	FILE * fp;
	fp =fopen("bubb_avg.txt", "a");
	fprintf(fp,"%d %lf\n",n, tt);
	
	//fwrite(a, sizeof(a), 1, fptr);
	//for(i=0;i<n;i++)
	//	printf("%lld ", a[i]);

}
