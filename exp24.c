#include <stdio.h>

int main()
{
    FILE *fp;
    char data[50];
    int choice;

    while(1)
    {
        printf("\n1.Create File");
        printf("\n2.Write File");
        printf("\n3.Read File");
        printf("\n4.Close");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            fp = fopen("test.txt", "w");
            printf("File created.\n");
            fclose(fp);
        }
        else if(choice == 2)
        {
            fp = fopen("test.txt", "a");
            printf("Enter data: ");
            scanf("%s", data);
            fprintf(fp, "%s\n", data);
            fclose(fp);
        }
        else if(choice == 3)
        {
            fp = fopen("test.txt", "r");
            printf("File contents:\n");
            while(fscanf(fp, "%s", data) != EOF)
                printf("%s\n", data);
            fclose(fp);
        }
        else if(choice == 4)
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

