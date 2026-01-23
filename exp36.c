#include <stdio.h>

int main()
{
    int i, n;
    int file[20];      // Blocks of the file
    int next[20];      // Pointer to next block

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter the block numbers (simulated):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &file[i]);

    // Create linked pointers
    for(i = 0; i < n - 1; i++)
        next[i] = i + 1;
    next[n - 1] = -1; // Last block points to -1

    printf("\nLinked File Allocation Table:\n");
    for(i = 0; i < n; i++)
    {
        if(next[i] != -1)
            printf("Block %d -> Next Block %d\n", file[i], file[next[i]]);
        else
            printf("Block %d -> NULL (last block)\n", file[i]);
    }

    // Simulate file access
    printf("\nAccessing file sequentially through linked blocks:\n");
    i = 0;
    while(i != -1)
    {
        printf("Reading Block %d\n", file[i]);
        i = next[i];
    }

    return 0;
}

