#include <stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include<ctype.h>
int check(char str[])
{
        int i;
        int n = strlen(str);
        for(i=0;i<n;i++)
        {
                if(!isdigit(str[i]))
                   return -1;
        }
        return 1;
}
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Usage (ip)  \n");
		return 0;
	}
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
          char a[50];
          nBytes = strlen(argv[2]) + 1;
          printf("Connecting to K ...\n");
	        sendto(clientSocket, argv[2], nBytes, 0, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
          printf("Connected to K ...\n");
          while(1)
          {
	          int zz = recvfrom(clientSocket, a,50, 0, (struct sockaddr *) &serverAddr, &addr_size);
	          a[zz] = '\0';
                  int cc = check(a);
                  if(cc==-1)
                  {
                      printf("Going to exit due to no num format \n");
                      exit(0);
                  }
                  else
                  {
                        int len = strlen(a);
                        printf("Received from K :%s\n",a);           
                        if(len==1)
                        {
                            printf("Now I am happy ... Thank you Server for helping .....!!!\n");
                            printf("Bye Bye K.. \n");
                            exit(0);
                        }
                  }
          }       
  return 0;
}
