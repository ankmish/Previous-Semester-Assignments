#include <stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include<ctype.h>
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Usage (ip)  \n");
		return 0;
	}
	int i;
          int clientSocket, portNum, nBytes; 
          struct sockaddr_in serverAddr, clad;
          socklen_t addr_size;
          clientSocket = socket(PF_INET, SOCK_DGRAM, 0);
          portNum = 7891;
          serverAddr.sin_family = AF_INET;
          serverAddr.sin_port = htons(portNum);
          serverAddr.sin_addr.s_addr = inet_addr(argv[1]);  
          clad.sin_family = AF_INET;
          clad.sin_port = htons(7892);
          clad.sin_addr.s_addr = htonl(INADDR_ANY); 
          bind(clientSocket,(struct sockaddr *) &clad, sizeof(clad));
          addr_size = sizeof serverAddr; 
          int a[50];
          printf("\n Enter the array :");
          int arr[6];
          	for(i=0;i<5;i++)
          		scanf("%d",&arr[i]);

          printf("Connecting to Server ...\n");
	        sendto(clientSocket, arr, sizeof(arr), 0, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
          printf("Connected to Server ...\n");
    
	          int zz = recvfrom(clientSocket, a,40, 0, (struct sockaddr *) &serverAddr, &addr_size);
	          printf("\nReceived andSorted by server\n");
	          for(i=0;i<5;i++)
	          	printf("%d ",a[i]);    
  return 0;
}
