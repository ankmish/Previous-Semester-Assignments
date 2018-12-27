#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char ** argv)
{
	int fd ;
	fd = open("aa.txt", O_RDONLY,0777);

	int n = lseek(fd,0,SEEK_END);
	int fd2 = open("bb.txt",O_CREAT  | O_RDWR,0777);
	char c;
	int sz = n;
	while(n>0)
	{
		int p = read(fd,&c,1);
		write(fd2,&c,p);
		lseek(fd,-2,SEEK_CUR);
		n--;
	}
	char st[sz+2];

	read(fd2,st,sz);
	st[sz]='\0';
	printf("%s\n",st);
	close(fd2);
	close(fd);
}