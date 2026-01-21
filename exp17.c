#include <stdio.h>

int main()
{
    int i, j, k;
    int n, m;
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], work[10];
    int finish[10], safe[10];
    int count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate Need matrix
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize
    for(i = 0; i < m; i++)
        work[i] = avail[i];

    for(i = 0; i < n; i++)
        finish[i] = 0;

    // Banker’s Algorithm
    while(count < n)
    {
        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                for(j = 0; j < m; j++)
                    if(need[i][j] > work[j])
                        break;

                if(j == m)
                {
                    for(k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    printf("\nSafe Sequence: ");
    for(i = 0; i < n; i++)
        printf("P%d ", safe[i]);

    return 0;
}

