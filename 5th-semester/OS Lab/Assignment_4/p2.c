#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>
int main()
{
    int fd[2];
    int depth = 0; // no. of genration from original
    int co;
    int i;
    pipe(fd);  // used by all children
    for(i=0; i<4; i++) 
    {
        if(fork() == 0)
        {   
            write(fd[1], &i, 1);  // write 1 byte for each child      //------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>
            depth += 1;
        }
    }
    
    close(fd[1]);        //----------->>>>>>>>>>>>>>>> IMP.... Why ????? Think of it !!!!
    /*Lets do it*/
    if( depth == 0 ) // original process
    {
      co=0;
      while(read(fd[0],&depth,1) != 0)   //------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        co += 1;
      printf( "%d total processes generated (except the original one)", co);

      FILE *fp = open("aa.txt","rw");
      fprintf(fp,"%d\n",co);               //----------------------------->>>>>>>>>>>>
    }
    return 0;
}
