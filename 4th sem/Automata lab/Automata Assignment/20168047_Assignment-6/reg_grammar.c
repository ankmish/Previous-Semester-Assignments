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
        if(P[i].r==1)
        con++;
        else if(P[i].r>1)
        {
            co=countVar(P[i].rhs,P[i].r);
            if(co>1)
            {
                flag=0;
                break;
            }
            else if(co==0)
            con++;
            else if(co==1)
            {
                if(isVar(P[i].rhs[0]))
                ll++;
                else if(isVar(P[i].rhs[P[i].r-1]))
                rl++;
            }
        }
    }
    printf("rl=%d ll=%d.\n",rl,ll);
    if(flag==0)
    printf("Non-Regular Grammar.\n");
    else
    {
        if(p==ll+con && rl==0)
        printf("Left Linear Grammar => Regular.\n");
        else if(p==rl+con && ll==0)
        printf("Right Linear Grammar => Regular.\n");
        else
        printf("Non-Regular Grammar.\n");
    }
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
int main()
{
    read();
    print();
    check();
    return 0;
}
