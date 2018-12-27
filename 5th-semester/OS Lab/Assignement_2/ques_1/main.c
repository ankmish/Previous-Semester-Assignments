#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<malloc.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void main(int argc,char **argv)
{
    if(argc<2)
    {
       printf("\n Too few arguments ...."); 
    }
    if(argc==2)
    {
        if(strcmp("pwd",argv[1])==0)
            execl("/home/akm/OS_lab/20168047_Ankit-Mishra_OS_LAB/Assignement_2/ques_1/pwd", "pwd", (char*)NULL);
	      else if(strcmp("ls",argv[1])==0)
           execl("/home/akm/OS_lab/20168047_Ankit-Mishra_OS_LAB/Assignement_2/ques_1/ls", "ls", (char*)NULL);
        else if(strcmp("exit",argv[1])==0)  
            execl("/home/akm/OS_lab/20168047_Ankit-Mishra_OS_LAB/Assignement_2/ques_1/exit", "exit", (char*)NULL);

    }
   if(argc==3)
   {
       if(strcmp("mkdir",argv[1])==0)
           execl("/home/akm/OS_lab/20168047_Ankit-Mishra_OS_LAB/Assignement_2/ques_1/mkdir", "mkdir", argv[2], (char*)NULL);
       if(strcmp("cd",argv[1])==0)
          execl("/home/akm/OS_lab/20168047_Ankit-Mishra_OS_LAB/Assignement_2/ques_1/cd", "cd", argv[2],(char*)NULL);
       if(strcmp("rmdir",argv[1])==0)
          execl("/home/akm/OS_lab/20168047_Ankit-Mishra_OS_LAB/Assignement_2/ques_1/rmdir", "rmdir", argv[2],(char*)NULL);
   }
}
