#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<unistd.h>
void main(int argc,char ** argv)
{
	DIR*p;
	struct dirent *d;
	if(argc==1)
	{
		char cwd[1024];
    		getcwd(cwd, sizeof(cwd));
    		p = opendir(cwd);
    		if(p==NULL)
		{
		  	  perror("Cannot find directory");
			  exit(-1);
     	}
		while(d=readdir(p))
		  printf("%s\n",d->d_name);
	}
	else
	{
		p=opendir(argv[1]);
		if(p==NULL)
		{
		  perror("Cannot find directory");
		  exit(-1);
		}
		while(d=readdir(p))
		  printf("%s\n",d->d_name);
	}
}
