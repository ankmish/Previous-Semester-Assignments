#include<stdio.h>
#include<stdlib.h>
int n;
struct process 
{ 
	int at,bt,pr,pno,ttt; 
}; 
struct process proc[50];    
int compar_AT(const void *a, const void *b)
{
	unsigned int l = ((struct process*)a)->at;
	unsigned int r = ((struct process*)b)->at;
	return (l-r);
}
int compar_TAT(const void *a, const void *b)
{
	unsigned int l = ((struct process*)a)->ttt;
	unsigned int r = ((struct process*)b)->ttt;
	return (l-r);
}
void get_wt_time(int wt[]) 
{ 
	// declaring service array that stores cumulative burst time  
	int service[50]; 
	service[0]=0; 
	wt[0]=0;
	int i;  	  
	for(i=1;i<n;i++) 
	{ 
		service[i]=proc[i-1].bt + service[i-1]; // ----------------------------->>>>>>>>>>>>>>>>>>>>>>>>
		wt[i]=service[i] - proc[i].at + 1; 		 // ------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>
		if(wt[i]<0) 
		{ 
		    wt[i]=0; 
		} 
	}  
} 
void get_tat_time(int tat[],int wt[]) 
{   
	int i;
	for(i=0;i<n;i++) 
	{ 
	    tat[i]=proc[i].bt + wt[i]; 
		proc[i].ttt = tat[i];
	}      
} 
void findgc() 
{ 
	int wt[50],tat[50],i; 	  
	double wavg=0,tavg=0; 
	get_wt_time(wt); 
	//Function call to find turnaround time 
	get_tat_time(tat,wt); 		 
	int stime[50],ctime[50]; 
	stime[0]=1; 
	ctime[0]=stime[0]+tat[0]; 
	// calculating starting and ending time 
	for( i=1;i<n;i++) 
	{ 
		   stime[i]=ctime[i-1]; 
		   ctime[i]=stime[i]+tat[i]-wt[i]; 
	} 		 
	printf("\nProcess_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time\n"); 		 
	for( i=0;i<n;i++) 
	{ 
		   wavg += wt[i]; 
		   tavg += tat[i]; 		     
		   printf("%d\t\t%d\t\t%d\t\t%d\t\t\t\t%d\n",proc[i].pno,stime[i],ctime[i],tat[i],wt[i]); 
	} 		 	  
}  
int main() 
{ 

	int i;	
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	printf("Enter burst times of processes in order\n");
	int bursttime[100],arrivaltime[100],priority[100];
	for(i=0;i<n;i++)
	{
		printf("\nEnter burst time : ");
		scanf("%d",&bursttime[i]);
		printf("\nEnter Arrival time :");
		scanf("%d",&arrivaltime[i]);
		printf("\nEnter priority :");
		scanf("%d",&priority[i]);
	}    
	for(i=0;i<n;i++) 
	{ 
	    proc[i].at=arrivaltime[i]; 
	    proc[i].bt=bursttime[i]; 
	    proc[i].pr=priority[i]; 
	    proc[i].pno=i+1; 
     }       
    qsort(proc,n,sizeof(struct process),compar_AT);      
    findgc();   
    printf("\n");
	qsort(proc,n,sizeof(struct process),compar_TAT);
	printf("\n Gantt Chart for the Priority with ARRIVAL TIME .......\n");
     for(i=0;i<n;i++)
	{
		if(i!=n-1)
			printf("  p%d  ->",proc[i].pno);
		else
			printf("  p%d \n",proc[i].pno);
	}
    return 0; 
} 
