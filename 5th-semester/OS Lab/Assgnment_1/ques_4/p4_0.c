#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

void main(int args,char **argc)
{ 
	 int fd1 = open("aa.txt",O_RDONLY,777);
	 int size = lseek(fd1,0,SEEK_END);   // 0 offset related to end of the file...reaches to end of the file
	 printf("\n File size is : %d ",size);
}
