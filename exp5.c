#include <stdio.h>

int main()
{
    int n, i, j;
    int bt[10], pr[10], wt[10], tat[10];
    int temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority (smaller number = higher priority):\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Process %d Priority: ", i + 1);
        scanf("%d", &pr[i]);
    }

    // Sort by priority
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(pr[i] > pr[j])
            {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], pr[i], wt[i], tat[i]);
    }

    return 0;
}

