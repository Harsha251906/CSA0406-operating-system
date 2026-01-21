#include <stdio.h>

int main()
{
    int i, j;
    int nb, np;
    int block[10], process[10];
    int alloc1[10], alloc2[10], alloc3[10];
    int min, max, index;

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

    // Initialize allocation arrays
    for(i = 0; i < np; i++)
        alloc1[i] = alloc2[i] = alloc3[i] = -1;

    /* ---------- FIRST FIT ---------- */
    for(i = 0; i < np; i++)
    {
        for(j = 0; j < nb; j++)
        {
            if(block[j] >= process[i])
            {
                alloc1[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    /* Reset block sizes */
    printf(""); // dummy statement to separate logic
    // Re-enter block sizes for next strategies
    printf("Re-enter block sizes:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    /* ---------- BEST FIT ---------- */
    for(i = 0; i < np; i++)
    {
        min = 9999;
        index = -1;

        for(j = 0; j < nb; j++)
        {
            if(block[j] >= process[i] && block[j] < min)
            {
                min = block[j];
                index = j;
            }
        }

        if(index != -1)
        {
            alloc2[i] = index;
            block[index] -= process[i];
        }
    }

    /* Reset block sizes again */
    printf("Re-enter block sizes:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    /* ---------- WORST FIT ---------- */
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
            alloc3[i] = index;
            block[index] -= process[i];
        }
    }

    printf("\nProcess\tFirstFit\tBestFit\t\tWorstFit\n");
    for(i = 0; i < np; i++)
    {
        printf("P%d\t", i + 1);

        if(alloc1[i] != -1) printf("B%d\t\t", alloc1[i] + 1);
        else printf("Not Alloc\t");

        if(alloc2[i] != -1) printf("B%d\t\t", alloc2[i] + 1);
        else printf("Not Alloc\t");

        if(alloc3[i] != -1) printf("B%d\n", alloc3[i] + 1);
        else printf("Not Alloc\n");
    }

    return 0;
}

