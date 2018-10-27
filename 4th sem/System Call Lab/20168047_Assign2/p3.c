#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
   pid_t my_pid, parent_pid, child_pid;
   int status;

   my_pid = getpid();
   parent_pid = getppid();
   printf("\n Parent: my pid is %d\n\n", my_pid);
   printf("Parent: my parent's pid is %d\n\n", parent_pid);

	child_pid = fork();
   if(child_pid < 0 )
   {
      perror("fork failure");
      exit(1);
   }


   if(child_pid == 0)
   {
   	  printf("\nChild: I am a new-born process!\n\n");
      my_pid = getpid();
      parent_pid = getppid();
      printf("Child: my pid is: %d\n\n",my_pid);
      printf("Child: my parent's pid is: %d\n\n", parent_pid);

      execl("/bin/ls", "/bin/ls", "-l", 0);
      perror("execl() failure!\n\n");

      printf("This print is after execl() and should not have been executed if execl were successful! \n\n");

      exit(1);
   }

   else
   {
      printf("\nParent: I created a child process.\n\n");
      printf("Parent: my child's pid is: %d\n\n", child_pid);

      wait(&status);
      printf("\n Parent: my child is dead. I am going to leave.\n \n ");
   }

   return 0;
}
