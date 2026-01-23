#include <stdio.h>

int main()
{
    int i, j, k;
    int n, frames;
    int page[20];
    int frame[10];
    int time[10];
    int counter = 0;
    int flag, pos;
    int pagefaults = 0;
    int min;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    // LRU Page Replacement
    for(i = 0; i < n; i++)
    {
        flag = 0;
        counter++;

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == page[i])
            {
                flag = 1;
                time[j] = counter;
                break;
            }
        }

        if(flag == 0)
        {
            pagefaults++;

            for(j = 0; j < frames; j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }
                else
                {
                    min = time[0];
                    pos = 0;
                    for(k = 1; k < frames; k++)
                    {
                        if(time[k] < min)
                        {
                            min = time[k];
                            pos = k;
                        }
                    }
                }
            }

            frame[pos] = page[i];
            time[pos] = counter;
        }

        printf("Frames: ");
        for(k = 0; k < frames; k++)
            printf("%d ", frame[k]);
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pagefaults);
    return 0;
}

