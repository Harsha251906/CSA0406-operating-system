#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int bt[10], rt[10], pr[10];
    int wt[10] = {0}, tat[10];
    int highest, min_pr;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Process %d Priority: ", i + 1);
        scanf("%d", &pr[i]);
        rt[i] = bt[i];   // remaining time
    }

    while(completed < n)
    {
        min_pr = 999;
        highest = -1;

        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0 && pr[i] < min_pr)
            {
                min_pr = pr[i];
                highest = i;
            }
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0)
        {
            completed++;
            tat[highest] = time;
            wt[highest] = tat[highest] - bt[highest];
        }
    }

    printf("\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], pr[i], wt[i], tat[i]);
    }

    return 0;
}

