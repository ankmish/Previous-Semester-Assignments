#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
pid_t pid;
int e;
pid = fork();
if(pid<0) {
perror("fork"); 
exit(1); 
}
else if(pid==0)
{                                    // its child process
printf(" CHILD: This is the child process!\n");
printf(" CHILD: My PID is %d\n", getpid());           // child ki id

printf(" CHILD: My parent's PID is %d\n", getppid());   // child ke parent ki id

printf(" CHILD: Enter the exit status of Child : ");
scanf("%d", &e);
printf(" CHILD: I'm outta here!\n");
exit(e);
}
else 
{
printf("PARENT: This is the parent process!\n");   // inside parent process
printf("PARENT: My PID is %d\n", getpid());        // parent ki id 
printf("PARENT: My child's PID is %d\n", pid);     // uski child ki id
printf("PARENT: I'm now waiting for my child to exit()...\n");    // waiting for child process to execute
wait(&e);
printf("PARENT: My child's exit status is: %d\n", WEXITSTATUS(e));  // exit status of the child process
printf("PARENT: I'm outta here!\n");
}
return 0;
}
