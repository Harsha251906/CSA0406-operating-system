#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    int users, files;
    char dir[10][20];
    char fname[10][10][20];

    printf("Enter number of users (directories): ");
    scanf("%d", &users);

    for(i = 0; i < users; i++)
    {
        printf("\nEnter name of directory %d: ", i + 1);
        scanf("%s", dir[i]);

        printf("Enter number of files in %s: ", dir[i]);
        scanf("%d", &files);

        for(j = 0; j < files; j++)
        {
            printf("Enter file %d name: ", j + 1);
            scanf("%s", fname[i][j]);
        }
    }

    printf("\n--- Two Level Directory Structure ---\n");
    for(i = 0; i < users; i++)
    {
        printf("\nDirectory: %s\n", dir[i]);
        printf("Files:\n");

        for(j = 0; j < files; j++)
            printf("%s\n", fname[i][j]);
    }

    return 0;
}

