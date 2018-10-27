#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct vertex
{
	int state;
	struct list *first;
};
struct vertex *graph[100001];

struct list
{
	struct list *next;
	char data;
	char value;
	int next_state;
};

struct vertex *insert(int index)
{
	struct vertex *tmp=(struct vertex *)malloc(sizeof(struct vertex ));
	tmp->state=index;
	tmp->first=NULL;
	return tmp;
}

void add_edge(struct vertex *ptr,char transition,char value, int new_state)
{
	struct list *tmp=(struct list *)malloc(sizeof(struct list ));
	tmp->next=NULL;
	tmp->data=transition;
	tmp->value=value;
	tmp->next_state=new_state;
	if(ptr->first==NULL)
	{
		ptr->first=tmp;
		return;
	}
	struct list *again=ptr->first;
	while(again->next!=NULL)
	{
		again=again->next;
	}
	again->next=tmp;
	return;
}
void check(int index, char str[], int len, int pos)
{
	struct vertex *ptr=graph[index];
	struct list *tmp=ptr->first;
	//char value;
	if(pos==len)
	{
		printf("\n");
		return;
	}
	while(tmp->data!=str[pos])
	{
		tmp=tmp->next;
	}
	printf("%c",tmp->value);
	check(tmp->next_state,str ,len, pos+1);
}

int main()
{
	int i,j,k,l,m,n,index,edges;
	char asso,transition,value;
	int new_state;
	printf("The no. of states:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the index and no. of edges: ");
		scanf("%d %d",&index,&edges);
		graph[index]=insert(index);
		for(j=1;j<=edges;j++)
		{
			printf("Enter the transition, value and new state: ");
			scanf(" %c %c %d",&transition,&value,&new_state);
			add_edge(graph[index],transition,value,new_state);
		}
	}
	printf("Enter the no. of strings you want to test: ");
	scanf("%d",&m);
	char str[100000];
	int len;
	for(i=1;i<=m;i++)
	{
		printf("Enter your string: ");
		scanf("%s",str);
		len=strlen(str);
		check(1,str,len,0);
	}
}