#include <stdio.h>

int main()
{
    int i, n, blocks;
    int index[20];
    int file[20];

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter the block numbers (simulated):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &file[i]);

    // Creating index block
    for(i = 0; i < n; i++)
        index[i] = file[i];

    printf("\nIndex Block Contents:\n");
    for(i = 0; i < n; i++)
        printf("Index[%d] -> Block %d\n", i, index[i]);

    printf("\nAccessing file using index block:\n");
    for(i = 0; i < n; i++)
        printf("Reading Block %d\n", index[i]);

    return 0;
}

