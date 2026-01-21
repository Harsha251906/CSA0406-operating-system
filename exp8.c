#include <stdio.h>

int main()
{
    int n, i, tq, time = 0, remain;
    int bt[10], rt[10], wt[10] = {0}, tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];   // remaining time
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    remain = n;

    while(remain > 0)
    {
        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0)
            {
                if(rt[i] > tq)
                {
                    time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                    remain--;
                }
            }
        }
    }

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
        printf("P%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);

    return 0;
}

