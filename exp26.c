#include <stdio.h>

int main()
{
    FILE *fp;
    char data[100];
    int choice;

    while(1)
    {
        printf("\n1. Create File");
        printf("\n2. Write File");
        printf("\n3. Read File");
        printf("\n4. Delete File");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            fp = fopen("file.txt", "w");
            printf("File created successfully\n");
            fclose(fp);
        }
        else if(choice == 2)
        {
            fp = fopen("file.txt", "a");
            printf("Enter data: ");
            scanf("%s", data);
            fprintf(fp, "%s\n", data);
            fclose(fp);
        }
        else if(choice == 3)
        {
            fp = fopen("file.txt", "r");
            printf("File contents:\n");
            while(fscanf(fp, "%s", data) != EOF)
            {
                printf("%s\n", data);
            }
            fclose(fp);
        }
        else if(choice == 4)
        {
            remove("file.txt");
            printf("File deleted successfully\n");
        }
        else if(choice == 5)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

