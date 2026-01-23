#include <stdio.h>

int main()
{
    int i, j, k;
    int n, frames;
    int page[20];
    int frame[10];
    int pos, flag, pagefaults = 0;
    int farthest, index;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    // Optimal Page Replacement
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
            pagefaults++;

            for(j = 0; j < frames; j++)
            {
                if(frame[j] == -1)
                {
                    frame[j] = page[i];
                    flag = 1;
                    break;
                }
            }

            if(flag == 0)
            {
                farthest = i + 1;
                index = -1;

                for(j = 0; j < frames; j++)
                {
                    for(k = i + 1; k < n; k++)
                    {
                        if(frame[j] == page[k])
                            break;
                    }

                    if(k == n)
                    {
                        index = j;
                        break;
                    }

                    if(k > farthest)
                    {
                        farthest = k;
                        index = j;
                    }
                }

                frame[index] = page[i];
            }
        }

        printf("Frames: ");
        for(k = 0; k < frames; k++)
            printf("%d ", frame[k]);
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pagefaults);
    return 0;
}

