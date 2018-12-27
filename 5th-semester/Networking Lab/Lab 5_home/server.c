#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include<string.h>
int check(char str[])
{
        int i;
        int n = strlen(str);
        for( i=0;i<n;i++)
        {
                if(!isdigit(str[i]))
                {
                        return -1;
                }
        }
        return 1;
}
int findsum(char str[])
{
        int num = atoi(str);
        int sum = 0;
        int rev;
        while(num > 0)
        {
                 rev = num % 10;
                 sum += rev;
                 num /= 10;
        }
        return sum;
}
 
int main()
{
	struct sockaddr_in addrport;
	int sockid=socket(PF_INET, SOCK_DGRAM, 0);
	if(sockid<0)
	{
		printf("Error In creating Socket\nPlease run again\n"); 
		return 0;
	}
	addrport.sin_family = AF_INET;
	addrport.sin_port = htons(7891);
	addrport.sin_addr.s_addr = htonl(INADDR_ANY);
	int status= bind(sockid,(struct sockaddr *) &addrport, sizeof(addrport));
	int count;	
	struct sockaddr_in caddr;
	char recvbuf[20];
	int len=sizeof(caddr);
	recvfrom(sockid, recvbuf, sizeof(recvbuf), 0, (struct sockaddr *) &caddr, &len);	
	printf("Recieved : %s\n",recvbuf);
	
	int sum = 0;
	int bb = check(recvbuf);
	if(bb==-1)
	{
	        char * buff;
	        buff = "Sorry, cannot compute ";
            printf("%s \n", buff);
	        sendto(sockid, buff, strlen(buff), 0, (struct sockaddr *) &caddr, sizeof(caddr));
	}
	else
    {
	        while(1)
	        { 
	            char  buff[100];
	            sum = findsum(recvbuf); 

	            sprintf(buff, "%d", sum);
	            
	            sendto(sockid, buff, strlen(buff), 0, (struct sockaddr *) &caddr, sizeof(caddr));
	            if(strlen(buff)==1)
	                 exit(0);

                for(int i=0;i<20;i++)
                    recvbuf[i] = 0;
                sprintf(recvbuf, "%d", sum);         
	        }
	}
	return 0;
}
