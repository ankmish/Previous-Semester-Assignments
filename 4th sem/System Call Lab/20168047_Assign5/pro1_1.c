/*
  Author : 				Ankit Mishra
  Registration No. :	20168047
  Program Name : 		Using FIFO/named pipe to establish connection between 2 different processes.
*/
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int fd;
    char * myfifo = "/tmp/myfifo";  // creating the file
    mkfifo(myfifo,0666);
    char sent[80],received[80];
    printf("Before Fun Begin \n");
    while(1)
    {
    	fd = open(myfifo,O_WRONLY);  // open the file for writing
    	fgets(sent,80,stdin);
    	write(fd,sent,strlen(sent)+1);  // write
    	close(fd);	
    	fd=open(myfifo,O_RDONLY);   // now open for reading the message from client
    	read(fd,received,sizeof(received));
    	printf("Client : %s\n",received);
    	close(fd);
    }
    return 0;
}
