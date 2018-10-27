/*
NAME    -  ANKIT MISHRA
DATE    - 15/03/2018
PROGRAM - To implement FRACTIONAL KNAPSACK using GREEDY ALGORITHM
*/
#include <stdio.h>
void fractional_knap(int cost[],int weights[],int W,int n)
{
    float tot_wt;
    int cur_wt,i,maxi;
    int sol[1000];
    for (i = 0; i < n; ++i)
        sol[i] = 0;
    cur_wt = W;
    while (cur_wt > 0)
    {
        maxi = -1;
        for (int i = 0; i < n;i++)
            if ((sol[i] == 0) && ((maxi == -1) || ((float)weights[i]/cost[i] > (float)weights[maxi]/cost[maxi])))
                maxi = i;
        sol[maxi] = 1; // object taken
        cur_wt -= cost[maxi];
        tot_wt += weights[maxi];
        if (cur_wt >= 0)
            printf("Added object %dth (%d rs., %dKg) completely in the bag. Space left: %d.\n", maxi + 1, weights[maxi], cost[maxi], cur_wt);
        else
        {
            printf("Added %d%% (%drs., %dKg) of object %d in the bag.\n", (int)((1 + (float)cur_wt/cost[maxi]) * 100), weights[maxi], cost[maxi], maxi + 1);
            tot_wt -= weights[maxi];
            tot_wt += (1 + (float)cur_wt/cost[maxi]) * weights[maxi];
        }
    }
    printf("Filled the bag with objects total of %.2f rs.\n", tot_wt);
}

int main()
{
    int n;
    printf("\n Enter the no. of elements :");
    scanf("%d",&n);
    int cost[n+2],weights[n+2],W;
    printf("\n Enter the cost of each elements :");
    for(int i=0;i<n;i++)
        scanf("%d", &cost[i]);
    printf("\n Enter the weight of each object :");
    for(int i=0;i<n;i++)
        scanf("%d", &weights[i]);
    printf("\n Enter the desired weight :");
    scanf("%d", &W);
    fractional_knap(cost,weights,W,n);
    return 0;
}
