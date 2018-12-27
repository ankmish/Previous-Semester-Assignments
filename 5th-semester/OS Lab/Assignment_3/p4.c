#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
int global_var = 25;
void main(int argc,char ** argv)
{
	int co = 0;
	 pid_t pid;
	 pid = fork();
	 if(pid<0)
	 	perror("Cant create a child");
	 while(1)
	 {
	      int local_var = 33;
	     co++;
	     if(pid==0)
	     {
	           printf("Address of global var and local var inside main child is : %d and %d \n",&global_var,local_var);
	           pid_t pid1;
	           pid1 = fork();
	           if(fork()==0)
	           {
	           	printf("Its the second child i.e, child of child\n");
	           	printf("Address of global var and local var inside child of child is : %d and %d \n",&global_var,local_var);
	           }
	           else
	           {
	           	printf("Address of global var and local var 1st child(main) is : %d and %d \n",&global_var,local_var);
	           }
	     }
	     else
	     {
	         printf("Its the first parent \n");
	         printf("Address of global var and local var inside main parent is : %d and %d\n",&global_var,local_var);
	     }
	     if(co>2)
	    	 break;
	 }
}
