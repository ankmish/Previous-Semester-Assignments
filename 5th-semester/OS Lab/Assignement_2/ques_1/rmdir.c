#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<stdlib.h>
void main(int argc,char ** argv)
{ 
   int check;
   char *dirname;
   dirname = argv[1];
   check = rmdir(dirname);
   if (!check)
      printf("Directory deleted\n");
   else
   {   
            printf("Unable to remove directory\n");
            exit(1);
   }
}
