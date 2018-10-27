/*
Author   -   Ankit Mishra
Reg. No. -   20168047
Date     -   04/02/18
Program  -   To Use NAMED PIPE FIFO as make a ECHO RECEIVER between SERVER and multiple CLIENTS
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define FIFO_NAME "myfile"
#define FIFO_NAME2 "myfile2"
int main()
{
	char s[520],s1[520];
  	int num, fd,fd2;
	mknod(FIFO_NAME, S_IFIFO | 0666, 0);
   	mknod(FIFO_NAME2, S_IFIFO | 0666, 0);
	printf("Waiting  for server...\n");	
    // Need two file descriptor as 2 client is there 
    fd = open(FIFO_NAME, O_WRONLY);     // for 1st client
    fd2 = open(FIFO_NAME2, O_RDONLY);   // for 2nd client
    printf("Connection Made \n");
    while (gets(s), !feof(stdin)) 
	{
    	strcpy(s1,"1\0");
    	strcat(s1,s);
        if ((num = write(fd, s1, strlen(s1))) == -1)
        		perror("write");                         //  error
        else
        		printf("GO : write %d bytes\n", num); //Successfully sent message
        if ((num = read(fd2, s, 500)) == -1)
            	perror("read");                        // error
        else 
		{
            	s[num] = '\0';
            	printf("Blue Tick: read %d bytes: \"%s\"\n", num, s); //Successfully read message
    	}
	}
    	close(fd);
    	close(fd2);
    	return 0;
}
