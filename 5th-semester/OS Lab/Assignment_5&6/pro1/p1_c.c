#include <stdio.h>
#include <stdlib.h>
struct process
{
	unsigned int pid;
	unsigned int burst;
	unsigned int burst_cpy;
	unsigned int rem_bt;
	unsigned int wait;
	unsigned int TAT;
};

int compar_ID(const void *a, const void *b)
{
	unsigned int l = ((struct process*)a)->pid;
	unsigned int r = ((struct process*)b)->pid;
	return (l-r);
}
int compar_BURST(const void *a, const void *b)
{
	unsigned int l = ((struct process*)a)->burst;
	unsigned int r = ((struct process*)b)->burst;
	return (l-r);
}
int compar_TAT(const void *a, const void *b)
{
	unsigned int l = ((struct process*)a)->TAT;
	unsigned int r = ((struct process*)b)->TAT;
	return (l-r);
}
void findWaitTime(int n, struct process proc[n], int quantum)
{
	int i;
	int flag = 0;

	unsigned int time_elapsed = 0;
	while(1)
	{
		flag = 1;
		for(i = 0 ; i < n ; i++)
		{
			if(proc[i].rem_bt > 0 )
			{
				flag = 0;
				if(proc[i].rem_bt > quantum)
				{
					time_elapsed +=quantum;
					proc[i].rem_bt -= quantum;
				}
				else
				{
					time_elapsed += proc[i].rem_bt;
					proc[i].wait = time_elapsed - proc[i].burst;  // ------------------------------>>>>>>>>>>>>>>>>>>>>>
					proc[i].rem_bt = 0;
				}
			}
		}
		if(flag == 1)
			break;
	}
}
void printTable(int n, struct process proc[n])
{
	int i;
	printf("\n%10s | %10s | %10s | %10s","P.NO.","BURST","WAIT","TAT");
	printf("\n------------------------------------------------------------------");
	int sum = 0,sum1=0;
	for(i = 0; i < n ; i++) {
		printf("\n%10d | %10d | %10d | %10d",proc[i].pid,proc[i].burst,proc[i].wait,proc[i].TAT);
		sum += proc[i].TAT;
		sum1 += proc[i].wait;
	}
	double avg = sum *(1.0) / n;
	printf("\n Avg. TAT is :%.3f ",avg);
	printf("\n Avg. WAITING TIME is : %.3f ",(sum1*(1.0))/n);
}
int main()
{
	int i,n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);

	struct process proc[n];
	printf("Enter burst times of processes in order\n");
	for(i=0;i<n;i++)
	{
		proc[i].pid = i+1;
		scanf("%d",&proc[i].burst);
		proc[i].rem_bt = proc[i].burst_cpy = proc[i].burst;
	}
	int quantum;
	printf("Enter the quantum for the RR:");
	scanf("%d",&quantum);
	findWaitTime(n,proc,quantum);
	for(i = 0; i < n ; i++)
		proc[i].TAT = proc[i].burst + proc[i].wait;
	printTable(n,proc);
	qsort(proc,n,sizeof(struct process),compar_TAT);
	printf("\n");
	printf("\n Gantt Chart for thr RR .......\n");
     for(i=0;i<n;i++)
	{
		if(i!=n-1)
			printf("  p%d  ->",proc[i].pid);
		else
			printf("  p%d \n",proc[i].pid);
	}
	
	return 0;
}
