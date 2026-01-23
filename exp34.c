#include <stdio.h>

int main()
{
    int n, i, choice, rec;
    int file[20];

    printf("Enter number of records in the file: ");
    scanf("%d", &n);

    printf("Enter the records:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &file[i]);

    while(1)
    {
        printf("\n1. Display all records");
        printf("\n2. Access a record");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Records in file: ");
            for(i = 0; i < n; i++)
                printf("%d ", file[i]);
            printf("\n");
        }
        else if(choice == 2)
        {
            printf("Enter record number to access (1-%d): ", n);
            scanf("%d", &rec);

            if(rec > 0 && rec <= n)
            {
                printf("Accessing records sequentially:\n");
                for(i = 0; i < rec; i++)
                    printf("%d ", file[i]);
                printf("\nRequested record: %d\n", file[rec - 1]);
            }
            else
            {
                printf("Invalid record number\n");
            }
        }
        else if(choice == 3)
            break;
        else
            printf("Invalid choice\n");
    }

    return 0;
}

