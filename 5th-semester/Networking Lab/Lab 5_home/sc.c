#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include<string.h>
int comp(const void * p,const void *q)
{
	int l = *(int *)p;
	int r = *(int *)q;

	return (l-r);
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
	int recvbuf[20];
	int len=sizeof(caddr);
	int gg = recvfrom(sockid, recvbuf, sizeof(recvbuf), 0, (struct sockaddr *) &caddr, &len);	
	printf("Recieved from client");
	int i;
	for(i=0;i<5;i++)
		printf("%d ",recvbuf[i]);

	printf("sorting ...");
	qsort(recvbuf,5,sizeof(arr[0]),comp);
	           
	sendto(sockid, recvbuf, sizeof(recvbuf), 0, (struct sockaddr *) &caddr, sizeof(caddr));      
	return 0;
}
