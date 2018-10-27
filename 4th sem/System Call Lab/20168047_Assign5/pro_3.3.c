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
#define FIFO_NAME3 "myfile3"
int main()
{
 	char s[540];
    int num, fd,fd2,fd3;
	mknod(FIFO_NAME, S_IFIFO | 0666, 0);
    mknod(FIFO_NAME2, S_IFIFO | 0666, 0);
    mknod(FIFO_NAME3, S_IFIFO | 0666, 0);
	printf("waiting for Client...\n");
	// Opening all files for communication
    fd = open(FIFO_NAME, O_RDONLY);
    fd2 = open(FIFO_NAME2, O_WRONLY);
    fd3 = open(FIFO_NAME3, O_WRONLY);
    printf("Got a Client\n");
	do
	{
        if ((num = read(fd, s, 500)) == -1)
     		perror("read");                          // error
    	else 
		{
       		s[num] = '\0';
     		printf("tick: read %d bytes: \"%s\"\n", num, s+1); //Message successfully read
        }
        if(s[0]=='1') //If 1st client
        {
		    if ((num = write(fd2, s+1, strlen(s)-1)) == -1)
		      	perror("write");                           // error
		    else
		       	printf("speak: wrote %d bytes\n", num); // Message sent successfully
        }
        else if(s[0]=='2')                             //If 2nd client
        {
		  	if ((num = write(fd3, s+1, strlen(s)-1)) == -1)
		     	perror("write");                           // error
		  	else
		        	printf("speak: wrote %d bytes\n", num); //Message sent successfully
        }
    } 
	while (num > 0);
    //Closing all files
	close(fd);
    close(fd2);
	close(fd3);
	return 0;
}
