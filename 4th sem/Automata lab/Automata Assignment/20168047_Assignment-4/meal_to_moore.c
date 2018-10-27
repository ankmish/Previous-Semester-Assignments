#include<stdio.h>
#include<string.h>
int main()
{
	int n,mat[20][5],mat2[20][5],x=0,i,j,k,c,newstates,flag[20][2]={0},split[20]={0},output[20],moo[20][4];
	printf("Enter the number of states.\n");
	scanf("%d",&n);
	newstates=n;
	printf("Enter the matrix of states & outputs for different inputs: \n");
	for(i=0;i<n;i++)
  	  for(j=0;j<5;j++)
 		 scanf("%d",&mat[i][j]);

	for(i=0;i<n;i++)
		for(j=1;j<5;j+=2)
		{
			flag[mat[i][j]][mat[i][j+1]]=1;
		}
	for(i=0;i<n;i++)
	{
		if(flag[mat[i][0]][0]==1&&flag[mat[i][0]][1]==1)
		{
			split[mat[i][0]]=1;
			newstates++;
			mat2[x][0]=mat[i][0]*10;
			mat2[x+1][0]=mat[i][0]*10+1;
			for(j=1;j<5;j++)
			{
				mat2[x][j]=mat[i][j];
				mat2[x+1][j]=mat[i][j];
			}
			c=2;
			for(j=i+1;j<n;j++)
			{
				for(k=0;k<5;k++)
				{
					mat2[x+c][k]=mat[j][k];
				}
				c++;
			}
			output[x++]=0;
			output[x++]=1;

		}
		else
		{
			for(j=0;j<5;j++)
                                mat2[x][j]=mat[i][j];
			if(flag[mat[i][0]][0]==1)
				output[x++]=0;
			else
				output[x++]=1;
		}
	}
	for(i=0;i<newstates;i++)
	{
		for(j=1;j<5;j+=2)
		{
			if(split[mat2[i][j]]==1)
				mat2[i][j]=mat2[i][j]*10+mat2[i][j+1];
		}
	}
	for(i=0;i<newstates;i++)
	{
		moo[i][0]=mat2[i][0];
		k=1;
		for(j=1;j<5;j+=2)
			moo[i][k++]=mat2[i][j];
		moo[i][k]=output[i];
	}
	printf("No of new states are %d\n",newstates);
	printf("Transition table of Moore machine is -:\n");
	for(i=0;i<newstates;i++)
	{
		for(j=0;j<4;j++)
			printf("%d\t",moo[i][j]);
		printf("\n");
	}
	return 0;
}
/*

Enter the number of states.
4
Enter the matrix of states & outputs for different inputs:
1 3 0 2 0
2 1 1 4 0
3 2 1 1 1
4 4 1 2 0
No of new states are 6
Transition table of Moore machine is -:
1       3       20      1
20      1       40      0
21      1       40      1
3       21      1       0
40      41      20      0
41      41      20      1

*/
