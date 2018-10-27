#include<stdio.h>
#include<stdlib.h>
#define M 100
struct node
{
    int s;
    int o;
}mealy[M][M];
int moore[M][M],o[M],n,sym;
void read()
{
    int i,k,j;
    printf("Enter the number of states\n");
    scanf("%d",&n);
    printf("Enter the number of symbols\n");
    scanf("%d",&sym);
    for(i=0;i<n;i++)
    {
        for(j=0;j<sym;j++)
        {
            printf("Enter (q%d,%d)-->q",i,j);
            scanf("%d",&moore[i][j]);
            printf("\n");
        }
        printf("Enter the output of state %d\n",i);
        scanf("%d",&o[i]);
    }
}
void convert()
{
    int i,k,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<sym;j++)
        {
            mealy[i][j].s=moore[i][j];
            mealy[i][j].o=o[i];
        }
    }
}
void print()
{
    int i,j,k;
    printf("\t");
    for(j=0;j<sym;j++)
    printf("\t%d",j);
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<sym;j++)
        {
            printf("\tq%d,%d",mealy[i][j].s,mealy[i][j].o);
        }
        printf("\n");
    }
}
int main()
{   
    read();
    convert();
    print();
    return 0;
}
