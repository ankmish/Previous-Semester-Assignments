#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
int i,h,flag=1;
char st[10];
printf("enter the string:");
scanf("%s",st);
int l=strlen(st);
for(i=0;i<l;i++)
{
h=isdigit(st[i]);
if(h==0)
{
flag=0;
break;
}
}
if(flag==0)
{printf("not constant");
}
else
printf("constant");
}
