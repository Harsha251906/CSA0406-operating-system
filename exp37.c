#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int n;
    int head;
    int req[20];
    int total = 0;
    int distance;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nDisk head movement:\n");
    for(i = 0; i < n; i++)
    {
        distance = abs(req[i] - head);
        total = total + distance;
        printf("%d -> %d\n", head, req[i]);
        head = req[i];
    }

    printf("\nTotal head movement = %d\n", total);
    return 0;
}

