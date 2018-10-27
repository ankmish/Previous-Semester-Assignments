#include<time.h>
#include<stdio.h>
long long int has[1000005],a[1000005],sorted[1000005],c[1000005];
void countSort(long long int arr[], long long int c[],long long int k,long long int n,long long int has[])
{
    int i;
    for(i=1;i<=k;i++)
    {
        c[i]=c[i-1]+c[i];
    }
    int j;
    for(j=n;j>=1;j--)
    {
        sorted[c[arr[j]]]=arr[j];
        c[arr[j]]--;
    }

}
int main()
{
     int n;
     long long int a[1000000];
    scanf("%d", &n);
    FILE * fp;
    fp=fopen("count_best.txt", "r");
    
    int i;
    long long int k;
    
       	clock_t start,end;
   	double tt;
    
    k=0;
    start=clock();
    for(i=0;i<1000004;i++)
        has[i]=0;
	for(i=0;i<n;i++)
   	{
   		 fscanf(fp,"%lld",&a[i]); 		 
   		  has[a[i]]++;
    	          c[a[i]]++;
    		if(a[i]>k)
        		k=a[i];
   	}
    countSort(a,c,k,n,has);
    
    end=clock();
	
	tt=((double)(end-start))/CLOCKS_PER_SEC;
	

	fclose(fp);
	FILE * fp1;
	fp1 =fopen("count_avg.txt", "a");
	fprintf(fp,"%d %lf\n",n, tt);
    
    return 0;
}
