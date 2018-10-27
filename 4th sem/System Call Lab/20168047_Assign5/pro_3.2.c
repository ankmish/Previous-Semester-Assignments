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
#define FIFO_NAME3 "myfile3"
int main()
{
    char s[520],s1[520];
    int num, fd,fd2;
	//Opening files to read and write
	mknod(FIFO_NAME, S_IFIFO | 0666, 0);
    mknod(FIFO_NAME3, S_IFIFO | 0666, 0);
	printf("Waiting for server...\n");
    fd = open(FIFO_NAME, O_WRONLY);
    fd2 = open(FIFO_NAME3, O_RDONLY);
    printf("connection Made \n");
    while (gets(s), !feof(stdin)) 
	{
    	strcpy(s1,"2\0");
    	strcat(s1,s);
        if ((num = write(fd, s1, strlen(s1))) == -1)
        		perror("write"); //Shouldn't execute
        else
         		printf("speak: wrote %d bytes\n", num); //Succesfully sent message
        if ((num = read(fd2, s, 500)) == -1)
        		perror("read"); //Shouldn't execute
        else 
		{
        	s[num] = '\0';
            printf("tick: read %d bytes: \"%s\"\n", num, s); //Successfully read message
        }
	}
	//Closing both files
    close(fd);
    close(fd2);
    return 0;
}
