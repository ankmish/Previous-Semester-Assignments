#include<stdio.h>
#include<string.h>
int main()
{

	int n,q[10]={0},i,j,k,x,sym,max,dfa[10][10]={0},fin,t[10][10],s,eq[10][10],flag,coun,setcount,out,grp;
	char c[10];
	printf("Enter the number of states.\n");
	scanf("%d",&n);

	printf("Enter the number of input symbols.\n");
	scanf("%d",&sym);

	printf("Enter the symbols.\n");
	scanf("%s",c);

	printf("Enter the number of final states.\n");
	scanf("%d",&fin);

	printf("Enter the final states.\n");
	for(i=0;i<fin;i++)
	{
		scanf("%d",&s);
		q[s]=1;
	}

	printf("Enter the transition rules: \n");
    for(i=0;i<n;i++)
    {
        if(q[i]==1)
            eq[0][i]=1;
        else
            eq[0][i]=0;
    }
	for(i=0;i<n;i++)
	{
		for(j=0;j<sym;j++)
		{
		    printf("Enter the transition for q(%d) -> %c: ",i,c[j]);
		    scanf("%d",&t[i][j]);
			printf("\n");
		}
	}
	setcount=1;
	for(x=1;;x++)    
    {
        eq[x][0]=eq[x-1][0];
        for(coun=0;coun<=setcount;coun++)
        {
            for(i=0;eq[x-1][i]!=coun && i<n;i++);
            eq[x][i]=eq[x-1][i];
            for(j=i+1;j<n;j++)
            {
                if(eq[x-1][i]==eq[x-1][j])
                {
                    flag=1;
                    for(k=0;k<sym;k++)
                    {
                        if(eq[x-1][t[i][k]]!=eq[x-1][t[j][k]])
                        {
                            eq[x][j]=setcount+1;  
                            max=setcount+1;
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1)
                        eq[x][j]=eq[x-1][j];
                }
            }
            setcount=max;
        }
        for(i=1;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(eq[x][i]==eq[x][j])
                {
                    for(k=0;k<sym;k++)
                    {
                        if(eq[x-1][t[i][k]]!=eq[x-1][t[j][k]])
                        {
                            eq[x][j]=setcount+1; 
                            max=setcount+1;
                            break;
                        }
                    }
                }
            }
            setcount=max;
        }
        printf("set(%d): ",x);
        flag=1;

        for(i=0;i<n;i++)
        {
            if(eq[x-1][i]!=eq[x][i])
                flag=0;
            printf("%d\t",eq[x][i]);
        }
        printf("\n");
        if(flag==1 || setcount>=n-1)
            break;
    }
    printf("No. of states in minimized DFA= %d\n",setcount+1);
    printf("Minimized DFA-:\n");
    for(i=0;i<sym;i++)
        printf("\t%c",c[i]);
    printf("\n");
    for(i=0;i<=setcount;i++)
    {
        for(j=0;j<n;j++)
        {
            if(eq[x][j]==i)
                printf("%d,",j);
        }
        printf("\b\t");
        for(k=0;k<sym;k++)
        {
            for(j=0;j<n;j++)
            {
                if(eq[x][j]==i)
                {
                    out=t[j][k];
                    grp=eq[x][out];
                    break;
                }
            }
            for(j=0;j<n;j++)
            {
                if(eq[x][j]==grp)
                    printf("%d,",j);
            }
            printf("\b\t");
        }
        printf("\n");
    }
    return 0;
}
