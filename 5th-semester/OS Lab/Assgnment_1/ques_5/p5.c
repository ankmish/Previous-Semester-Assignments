#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include <stdlib.h>
#include<dirent.h>
void main(int argc,char ** argv)
{
	char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) == NULL)
   		perror("getcwd() error");
   	else
   		printf("current working directory is: %s\n", cwd);

  	char * path = argv[1];

  	chdir(argv[1]);  // change the current directory

  	char cw[256];
  	if (getcwd(cw, sizeof(cwd)) == NULL)
   		perror("getcwd() error");
   	else
   		printf("\n Now current working directory is(after changing): %s\n", cw);
  	char cmd[500];
  	printf("\n Listing the files in current direcotry with their inode details ...\n");

	DIR *pdir;
	pdir=opendir(cw);

	if(pdir==NULL)
		printf("The given direcotry cannot be opened\n");
	else 
	{
		struct dirent *pdirent;
		while((pdirent=readdir(pdir))!=NULL)
		{
			printf("%s :",pdirent->d_name);
			printf("%ld",pdirent->d_ino);
			printf("\n");
		}

		closedir(pdir);  	

	}
}
