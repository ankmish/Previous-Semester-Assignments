#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>  
struct Process 
{ 
    int pid; 
    int bt; 
    int art; 
    int wt;
    int tat;
    int rem_bt;
}; 
void findWaitingTime(struct Process proc[], int n)
{ 
    int complete = 0,t = 0,minm = 999999; 
    int shortest = 0, finish_time; 
    int flag = 0; 

    // we are checking at each second if some new process with SRT is arrived
    while (complete != n) 
    { 
  
        for (int j = 0; j < n; j++)        // min. rem  time process if present at particular time "t"
        {       
            if ((proc[j].art <= t) && (proc[j].rem_bt < minm) && proc[j].rem_bt  > 0) 
            { 
                minm = proc[j].rem_bt;
                shortest = j; 
                flag = 1; 
            } 
        } 
  
        if (flag == 0) 
        { 
            t++; 
            continue; 
        } 
        proc[shortest].rem_bt--;

        minm = proc[shortest].rem_bt;
        if (minm == 0)               // if this process completed..
            minm = 999999; 
  
        if (proc[shortest].rem_bt == 0) 
        { 
            complete++; 
            flag = 0; 
            finish_time = t + 1; 
            proc[shortest].wt = finish_time - proc[shortest].bt - proc[shortest].art; 
  
            if (proc[shortest].wt < 0) 
                proc[shortest].wt = 0; 
        } 
        t++; 
    } 
} 
void findTurnAroundTime(struct Process proc[], int n)
{ 
    for (int i = 0; i < n; i++) 
        proc[i].tat = proc[i].bt + proc[i].wt; 
} 
void findavgTime(struct Process proc[], int n) 
{ 
    findWaitingTime(proc,n); 
    findTurnAroundTime(proc, n); 
   
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnAround Time\n");
    for (int i = 0; i < n; i++) 
        printf("%d\t%d\t\t%d\t\t\t%d\n",proc[i].pid,proc[i].bt,proc[i].wt,proc[i].tat);
} 
int main() 
{ 
    int n;
    printf("\n Enter the number of the process :");
    scanf("%d", &n);
    int i;
    int bt[n+2];
    int at[n+2];
    int pid[n+2];
    int rem_bt[n+2];
    printf("\n");
    struct Process proc[n+2];
    printf("\n Enter Burst Time , Arrival Time :");
    for(i=0;i<n;i++)
    {
        pid[i] = i;
        scanf("%d %d",&bt[i],&at[i]);
        rem_bt[i] = bt[i];
    }
    for(i=0;i<n;i++)
    {
        proc[i].pid = i;
        proc[i].bt = bt[i];
        proc[i].art = at[i];
        proc[i].rem_bt = rem_bt[i];
    }
    findavgTime(proc,n); 
    return 0; 
} 
