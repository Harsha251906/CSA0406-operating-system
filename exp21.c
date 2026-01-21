#include <stdio.h>

int main()
{
    int i, j;
    int nb, np;
    int block[10], process[10];
    int alloc[10];
    int max, index;

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

    // Worst Fit Allocation
    for(i = 0; i < np; i++)
    {
        max = -1;
        index = -1;

        for(j = 0; j < nb; j++)
        {
            if(block[j] >= process[i] && block[j] > max)
            {
                max = block[j];
                index = j;
            }
        }

        if(index != -1)
        {
            alloc[i] = index;
            block[index] -= process[i];
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

