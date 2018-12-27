#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
int main(int argc,char ** argv)
{
	rc= chdir(argv[1]);
	if (rc) 
	{
	    int ern= errno;
	    fprintf (stderr, "*** Error in chdir('%s') errno=%d: %s\n",directory, ern, strerror (ern));
	}
	 
}
