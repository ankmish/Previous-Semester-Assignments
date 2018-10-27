#include<stdio.h>
#include<string.h>
#define M 1000
struct Productions
{
    char lhs[M];
    char rhs[M];
    int l,r;
}P[M];
int v,t,p;
char V[M],T[M],S;
int isVar(char c)
{
    int i;
    for(i=0;i<v;i++)
    if(V[i]==c)
    return 1;
    return 0;
}
int isTer(char c)
{
    int i;
    for(i=0;i<t;i++)
    if(T[i]==c)
    return 1;
    return 0;
}
int countVar(char c[],int l)
{
    int co=0,i;
    for(i=0;i<l;i++)
    if(isVar(c[i]))
    co++;
    return co;
}
void read()
{
    int i,j;
    printf("Enter the number of variables:\n");
    scanf("%d",&v);
    printf("Enter the variables:\n");
    for(i=0;i<v;i++)
    scanf(" %c",&V[i]);
    printf("Enter the number of terminal symbols:\n");
    scanf("%d",&t);
    printf("Enter the terminal symbols:\n");
    for(i=0;i<t;i++)
    scanf(" %c",&T[i]);
    T[t++]='e';
    printf("Enter the start symbol:\n");
    scanf(" %c",&S);
    printf("Enter the number of productions:\n");
    scanf("%d",&p);
    printf("Enter the productions:\n");
    for(i=0;i<p;i++)
    {
        printf("Enter the lhs.\n");
        scanf("%s",P[i].lhs);
        printf("Enter the rhs.\n");
        scanf("%s",P[i].rhs);
        P[i].l=strlen(P[i].lhs);
        P[i].r=strlen(P[i].rhs);
    }    
}
void print()
{
    int i,j;
    printf("The Entered Grammar is:\n");
    printf("V={");
    for(i=0;i<v;i++)
    printf("%c,",V[i]);
    printf("}\n");
    printf("T={");
    for(i=0;i<t;i++)
    printf("%c,",T[i]);
    printf("}\n");
    printf("S= %c\n",S);
    printf("Productions:\n");
    for(i=0;i<p;i++)
    {
        printf("%s --> %s\n",P[i].lhs,P[i].rhs);
    }
    printf("\n");
}
void check()
{
    int i,j,ll=0,rl=0,con=0,flag=1,co=0;
    for(i=0;i<p;i++)
    {
        if(P[i].l>1)
        {
            flag=0;
            break;
        }
        else if(P[i].l==1 && isTer(P[i].lhs[0]))
        {
            flag=0;
            break;
        }
    }
    for(i=0;i<v;i++)
    {
        if(isTer(V[i]))
        {
            flag=0;
            break;
        }
    }
    for(i=0;i<t;i++)
    {
        if(isVar(T[i]))
        {
            flag=0;
            break;
        }
    }
    if(flag==0)
    printf("Non Context Free Grammar.\n");
    else
    printf("Context Free Grammar.\n");
}
int main()
{
    read();
    print();
    check();
    return 0;
}
