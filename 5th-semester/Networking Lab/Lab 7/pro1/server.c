#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
        int count; 
        int co=0;
	struct sockaddr_in addrport;
	struct sockaddr_in caddr;

	if(argc!=2)
	{
	        printf("Usage (port)\n");
	        return 0;
	}
        // create the socket
	int sockid=socket(PF_INET, SOCK_STREAM, 0);

	if(sockid<0)
	{
	        printf("Error in creating Socket\n"); 
	        return 0;
	}
	// assign the port 
	int port=atoi(argv[1]);
	addrport.sin_family = AF_INET;
	addrport.sin_port = htons(port);
	addrport.sin_addr.s_addr = htonl(INADDR_ANY);

	int status= bind(sockid,(struct sockaddr *) &addrport, sizeof(addrport));
	
	if(listen(sockid,5)<0) 
	        printf("Listening error\n");
	        
	// Server is now ready to listen on specified port 
	printf("Server listening on port %d..  \n",port);
	
	while(1)
	{
		char str[20];

		unsigned int lenc=sizeof(caddr);

		int s = accept(sockid,(struct sockaddr *) &caddr,&lenc);		
		inet_ntop(AF_INET, &(caddr.sin_addr), str, lenc);
		// connecitng multi client
		printf("Client [%d] %s connected on port %d\n",++co,str,port);


		if(fork()==0)                                       // child
		{
			char recvbuf[20]="";
			char rev[20];	
			int len = recv(s,recvbuf,20, 0);
			recvbuf[len] = '\0';
			printf("Client %d sent : %s \n",co,recvbuf);
			int i=0,j;
			for(i=strlen(recvbuf)-1,j=0;i>=0;i--) 
			        rev[j++]=recvbuf[i];
			        
			rev[j]='\0';	

			send(s,rev,sizeof(rev),0);
			close(s);   // close  socket 's'          ...1 
			exit(0);
		}
		close(s);                        // 2...                        socket 's' is closed at 2 place
	}
	
	close(sockid);
	return 0;
}
