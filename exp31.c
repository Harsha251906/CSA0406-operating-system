#include <stdio.h>

int main()
{
    int i, j, k;
    int n, frames;
    int page[20];
    int frame[10];
    int flag, pagefaults = 0;
    int index = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    // FIFO Page Replacement
    for(i = 0; i < n; i++)
    {
        flag = 0;

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == page[i])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            frame[index] = page[i];
            index = (index + 1) % frames;
            pagefaults++;
        }

        printf("Frames: ");
        for(k = 0; k < frames; k++)
            printf("%d ", frame[k]);
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pagefaults);
    return 0;
}

