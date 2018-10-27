#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,j,states,fstates,alpha;
	printf("Enter number of states\n");
	scanf("%d",&states);
	printf("Enter number of final states\n");
	scanf("%d",&fstates);
	printf("Enter number of input alphabets\n");
	scanf("%d",&alpha);
	char c[alpha];
	int f[fstates+1],dfa[states][states],n,g;
	for(i=0;i<alpha;i++){
		printf("\nEnter alphabet %d: ",i+1);
		scanf(" %c",&c[i]);
	}
	for(i=0;i<fstates;i++)
	{
		printf("\nEnter final state %d q",i+1);
		scanf("%d",&f[i]);
	}
	printf("Create transition function: (Q*E->Q)\n");
	for(i=0;i<alpha;i++)
	{
		for(j=0;j<states;j++)
		{
			printf("(q%d,%c)-->q",j,c[i]);
			scanf("%d",&dfa[j][i]);
		}
	}
	printf("Enter the string to be checked\n");
	char str[20];
	scanf("%s",str);
	i=0,n=0;
	while(str[i]!='\0')
	{
		g=0;
		for(j=0;j<alpha;j++)
		if(c[j]==str[i])
		break;
		n=dfa[n][j];
		for(j=0;j<fstates;j++)
		if(n==f[j])
		g=1;
		i++;
	}
	if(g==1)
	printf("Valid string\n");
	else printf("Invalid string\n");
	return 0;
}
