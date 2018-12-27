#include<stdio.h>
#include<math.h>
int main(){
    // array to store binary number 
    long long int binaryNum[33]; 
  	
  	
  	printf("enter page size in KB \n");
  	int page_size;
  	scanf("%d",&page_size);
  	int p=0;
  	
  	while(page_size!=0){
  		
  		page_size/=2;
  		p++;
  	}
  	
  	int offsetbit=10+p-1;
  	printf("%d",offsetbit);
  	
  	printf("enter the virtual address\n");
  	long long  int vir_add;
  	
  	scanf("%lld",&vir_add);
  	long long int n=vir_add;
  	//counter for binary array 
    int i = 0; 
    while (n > 0) { 
      
        //storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; }
        
           
  	
  	
  	long long int sum=0;
  	for(i=offsetbit-1;i>=0;i--){
  	sum=sum+(binaryNum[i]*pow(2,i));
  	}
  	
  	printf("\noffset=%lld",sum);
  	
  	long long int pagenum=(long long int)vir_add/(page_size*1024);
  	printf("page number=%lld",pagenum);
  	
  	}
  	
  	

