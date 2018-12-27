#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void main(int args,char **argc )
{
	int fd;
	int offset;
	fd = open("foo1.txt",O_CREAT | O_RDWR | O_TRUNC ,777);
	char wr[100] = "Ankit Mishra";
	int len = strlen(wr);
	int size = write(fd,wr,len);
	close(fd);
	char c;
	fd = open("foo1.txt",O_RDONLY,777);
	offset = lseek(fd, 0, SEEK_END);
	//printf("%d\n",offset);
	int fd2 = open("foorev.txt", O_RDWR | O_CREAT, 0770);
	while (offset > 0) 
	{     
          int n = read(fd, &c, 1);  //read a char                           ////////////////////////////////////// eroooooooorroorrrrrrrrrrrrrrrrrrrrrrr
         // printf("%c ",c);
          write(fd2, &c, 1);  //write the char
          lseek(fd, -2, SEEK_CUR);   //go back 2 spots to the char before the one just read
          offset--;     //track the current offset
     }
    char rd[size+2];
    close(fd2);
    fd2 = open("foorev.txt", O_RDWR,0777);
    int n = read(fd2,rd,size);
	printf("%d\n",n);
	rd[size]='\0';
	printf("%s ",rd);
	close(fd2);
    close(fd);
	link("foo1.txt","foo2.txt");
	fd = open("foo.txt", O_CREAT | O_WRONLY,777);
	write(fd,rd,size);
	close(fd); 
	unlink("foo2.txt");
	
}

