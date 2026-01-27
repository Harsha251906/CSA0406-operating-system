#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    int req[5];
    int head = 50;
    int disk_size = 200;
    int seek = 0;
    int i, j, temp;

    /* Initialize request queue using for loop */
    for (i = 0; i < n; i++)
    {
        req[i] = (i + 1) * 20;   // 20, 40, 60, 80, 100
    }

    /* Sort the request array */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (req[i] > req[j])
            {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    printf("C-SCAN Disk Scheduling\n");
    printf("Head starts at: %d\n", head);

    /* Move towards higher tracks */
    for (i = 0; i < n; i++)
    {
        if (req[i] >= head)
        {
            seek += abs(req[i] - head);
            head = req[i];
            printf("Head moves to %d\n", head);
        }
    }

    /* Move to end of disk */
    seek += abs((disk_size - 1) - head);
    head = disk_size - 1;

    /* Jump from end to start */
    seek += abs(head - 0);
    head = 0;

    /* Service remaining requests */
    for (i = 0; i < n; i++)
    {
        if (req[i] < head)
        {
            seek += abs(req[i] - head);
            head = req[i];
            printf("Head moves to %d\n", head);
        }
    }

    printf("Total seek time = %d\n", seek);

    return 0;
}

