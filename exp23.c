#include <stdio.h>

int main()
{
    int i, j;
    int nb, np;
    int block[10], process[10];
    int alloc[10];

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter size of each block:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter size of each process:\n");
    for(i = 0; i < np; i++)
        scanf("%d", &process[i]);

    for(i = 0; i < np; i++)
        alloc[i] = -1;

    // First Fit Allocation
    for(i = 0; i < np; i++)
    {
        for(j = 0; j < nb; j++)
        {
            if(block[j] >= process[i])
            {
                alloc[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    printf("\nProcess\tProcess Size\tBlock Allocated\n");
    for(i = 0; i < np; i++)
    {
        printf("P%d\t\t%d\t\t", i + 1, process[i]);

        if(alloc[i] != -1)
            printf("B%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

