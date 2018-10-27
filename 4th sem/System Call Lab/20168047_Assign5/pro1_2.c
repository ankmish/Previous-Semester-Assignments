/*
  Author : 				Ankit Mishra
  Registration No. :	20168047
  Program Name : 		Using FIFO (named pipe) to establish connection between 2 different processes.
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
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo,0666);
    char sent[100],received[100];
    while(1)
    {  	
    	fd=open(myfifo,O_RDONLY);             // Client read the message from server ,,,therefore, read only mode
    	read(fd,received,sizeof(received));
    	printf("Server : %s\n",received);
    	close(fd);
    	fd = open(myfifo,O_WRONLY);     // for server to reply ... write mode
    	fgets(sent,80,stdin);
    	write(fd,sent,strlen(sent)+1);
    	close(fd);
    }
    return 0;
}
