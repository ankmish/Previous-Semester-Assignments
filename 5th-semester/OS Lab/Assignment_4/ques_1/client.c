#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>
void main(int argc,char ** argv)
{
	int stat;
	pid_t pid;
	int a,b;
	char c[10];
	printf("\n Enter the first and second number :");
	scanf("%d %d", &a,&b);
	char num1[10];
	char num2[10];
  	sprintf(num1, "%d", a); // ------------------------------------------------->>>>>>>>>>>
  	sprintf(num2, "%d", b);  // ------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  	printf("\n Enter the operend(+ or -) :");
	scanf("%s", c);
	pid = fork();
	if(pid<0)
		perror("Cant fork ...");
	else if(pid==0)
	{
		execl("/home/user/Desktop/20168047_oslab4/ques_1/server","server",num1,num2,c,NULL);
	}
	else
	{
		wait(&stat);
		if(WIFEXITED(stat))
			printf("\n Result(in parent) is : %d\n", WEXITSTATUS(stat));   ///------------------->>>>>>>>>>>>>>>>>>>>>>>>>
	}
}
