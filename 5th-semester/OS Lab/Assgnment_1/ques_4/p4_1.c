#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

void main(int args,char **argc)
{ 
	struct stat stbuf;
	stat("aa.txt",&stbuf);
	printf("File size is  : %d\n", stbuf.st_size);
     printf("No. of blocks assigned =  : %d ",stbuf.st_blksize);
}