#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
struct inp
{
	int a,b;
	char c;
};
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Usage (hostname) (port)\n");
		return 0;
	}
	int clientSocket, portNum, nBytes,sv;
	char buffer[1000];
	char a[100];
	struct sockaddr_in serverAddr, clad;
	socklen_t addr_size;
	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	portNum = atoi(argv[2]);


 // here ratta (mtlb function ka ratta ) begins

	struct hostent *he;         //--------------->>>>>>>>>>>>>>>>>>>
	struct in_addr **ad;       //----------------->>>>>>>>>>>>>>>>>>>>>

	if ((he = gethostbyname(argv[1])) == NULL) 
	{
	    herror("Error");
	    return 1;
	}
	ad=(struct in_addr **) he->h_addr_list;      //------------->>>>>>>     
	char ip[100];

	strcpy(ip,inet_ntoa(*ad[0]));   //---------->>>>>>>>>>>>>>


// hetre ratta ends


	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(portNum);
	serverAddr.sin_addr.s_addr = inet_addr(ip);
	addr_size = sizeof serverAddr;
	if(connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size)<0)
	{ 
			printf("Connection error\n");
			return 0;
	}
	else
		printf("Connected to %s:%d \n",ip,portNum);

	printf("What do you want to calculate ?\n Operator1 Operator(+ - * / ^) Operator2 : ");
	struct inp  in;
	//in = (struct inp *)malloc(sizeof(struct inp));
	printf("\n Enter experssion :");
	{
		scanf("%d %c %d",&(in.a),&(in.c),&(in.b));
	}
	//nBytes = strlen(buffer) + 1;
	send(clientSocket,&in,sizeof(in),0);
	char ab[20];
	recv(clientSocket, ab, 1000, 0);
	printf("Received from client : %s \n",ab);   
	
	close(clientSocket);
	return 0;
}