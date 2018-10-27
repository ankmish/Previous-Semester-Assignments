#include<stdio.h>
#include<string.h>
#include<math.h>
int top=-1,st[100];
void push(int a)
{
	st[top+1]=a;
	top++;
}
int pop()
{
	int e = st[top];
	top--;
	return e;
}
int isEmpty()
{
	if(top==-1)
		return 1;
	return 0;
}
int main()
{

	int n,q[10]={0},qd[10]={0},in[100],i,j,k,sym,sy,nfa[10][10][10]={0},dfa[1030][10]={0},fin,t[10][10],s,flag[10]={0};
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
		for(j=0;j<sym;j++)
		{
		    printf("Enter the number of transitions for q(%d) -> %c: ",i,c[j]);
		    scanf("%d",&t[i][j]);

		    for(k=0;k<t[i][j];k++)
		    {
		        printf("Enter transition %d for q(%d) -> %c: ",k,i,c[j]);
		        scanf("%d",&nfa[i][j][k]);
		    }
		    printf("\n");
		}
	}
	for(i=1;i<pow(2,n);i++)
    	{
	    for(j=0;j<n;j++)	//a dfa state is final if the bit of any final state of nfa is set in it
	    {		
		if((1<<j & i) !=0 && q[j]==1)	//bit is set or not, set bit (state of nfa) is final or not	
		{	
			//printf("State %d final.\n",i);			
			qd[i]=1; 
			break;
		}
	    }
	    for(sy=0;sy<sym;sy++)
		dfa[i][sy]=0;
	    for(j=0;j<n;j++)	
	    {		
		if((1<<j & i) !=0 )	//if jth state is present	
		{
		    for(sy=0;sy<sym;sy++) //for every symbol
		    {
			    for(k=0;k<t[j][sy];k++) //for every transition for symbol sy
			    {
				dfa[i][sy] = dfa[i][sy] | (1 << nfa[j][sy][k]);
			    }
		    }
		}
	   }
    	}
	int visited[1030]={0},print[1030]={0};
	for(i=0;i<sym;i++)
		printf("\t%c",c[i]);
	printf("\n");
	
	/*for(i=1;i< pow(2,n);i++)         //printing all states
	{
		printf("q[%d]\t",i);
		for(j=0;j<sym;j++)
		{
		    if(dfa[i][j]==0)
	       		 printf("-\t");
	    	    else
	       		 printf("q[%d]\t",dfa[i][j]);
		}
		printf("\n");
	}*/
	push(1); 
	visited[1]=1;
	while(!isEmpty())	//printing only required states
	{
		i=pop();	
		printf("q[");
		for(k=0;k<n;k++)	//printing all set bits in i
		{
			if((1<<k & i)!=0)
       			printf("%d",k);
		}
		printf("]\t");
		for(j=0;j<sym;j++)
		{
		    if(visited[dfa[i][j]]==0 && dfa[i][j]!=0)
		    { 
			push(dfa[i][j]);
		  	visited[dfa[i][j]]=1;
		    }

		    if(dfa[i][j]==0)
	       		 printf("-\t");
	    	    else
		    {
			printf("q[");
			for(k=0;k<n;k++) //printing all set bits in dfa[i][j]
			{
				if((1<<k & dfa[i][j])!=0)
	       			printf("%d",k);
			}
			printf("]\t");
		    }

		}
		printf("\n");
	}
	char str[1000];
	printf("\nEnter the string.\n");
	scanf("%s",str);
	int l=strlen(str);
	char z=c[0];
	int s0=1,snext;
	for(i=0;i<l;i++)
	{
		snext=dfa[s0][str[i]-z];
		s0=snext;
	}
	if(qd[s0]==1)
		printf("Valid string.\n");
	else
		printf("Invalid string.\n");
	return 0;
}

/*
muskan@muskan-HP-Pavilion-Notebook:~/Documents/AutomataLab/3$ gcc NFA.c -lm
muskan@muskan-HP-Pavilion-Notebook:~/Documents/AutomataLab/3$ ./a.out
Enter the number of states.
3
Enter the number of input symbols.
2
Enter the symbols.
ab
Enter the number of final states.
1
Enter the final states.
2
Enter the transition rules: 
Enter the number of transitions for q(0) -> a: 2
Enter transition 0 for q(0) -> a: 0
Enter transition 1 for q(0) -> a: 1

Enter the number of transitions for q(0) -> b: 1
Enter transition 0 for q(0) -> b: 2

Enter the number of transitions for q(1) -> a: 1
Enter transition 0 for q(1) -> a: 0

Enter the number of transitions for q(1) -> b: 1
Enter transition 0 for q(1) -> b: 1

Enter the number of transitions for q(2) -> a: 0

Enter the number of transitions for q(2) -> b: 2
Enter transition 0 for q(2) -> b: 0
Enter transition 1 for q(2) -> b: 1

	a	b
q[0]	q[01]	q[2]	
q[2]	-	q[01]	
q[01]	q[01]	q[12]	
q[12]	q[0]	q[01]	

Enter the string.
abbab
Valid string.
muskan@muskan-HP-Pavilion-Notebook:~/Documents/AutomataLab/3$ 

*/


