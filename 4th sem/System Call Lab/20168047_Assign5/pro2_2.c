/*
Author   -   Ankit Mishra
Reg. No. -   20168047
Date     -   04/02/18
Program  -   To use NAMED PIPE FIFO to implement the two process where one of them will execute the ls -l and output of it act 
             as a input for the other process. 
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
int main()
{
    char s[520];
    int num, fd,fd1;
	mknod(FIFO_NAME, S_IFIFO | 0666, 0);
	printf("Waiting for client...\n");
    fd = open(FIFO_NAME, O_WRONLY);             //Opening file to write
    printf("Client Found\n");
    close(1);
    fd1=dup(fd);                                //Duplicating file descriptor
	system("ls -l");                            //Performing ls -l
    close(fd);                              //Closing file
    return 0;
}
