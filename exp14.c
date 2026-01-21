#include <stdio.h>
#include <string.h>

int main()
{
    int choice, i, n = 0;
    char files[10][20], fname[20];
    int found;

    while(1)
    {
        printf("\n--- Single Level Directory ---\n");
        printf("1. Create File\n");
        printf("2. Display Files\n");
        printf("3. Search File\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter file name: ");
            scanf("%s", fname);

            strcpy(files[n], fname);
            n++;
            printf("File created successfully.\n");
        }
        else if(choice == 2)
        {
            if(n == 0)
                printf("Directory empty.\n");
            else
            {
                printf("Files in directory:\n");
                for(i = 0; i < n; i++)
                    printf("%s\n", files[i]);
            }
        }
        else if(choice == 3)
        {
            printf("Enter file name to search: ");
            scanf("%s", fname);

            found = 0;
            for(i = 0; i < n; i++)
            {
                if(strcmp(files[i], fname) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if(found)
                printf("File found.\n");
            else
                printf("File not found.\n");
        }
        else if(choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

