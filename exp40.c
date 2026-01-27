#include <stdio.h>

int main()
{
    char users[3][10] = {"Owner", "Group", "Others"};
    char perm[3][4];
    int i;

    /* Initialize permissions using for loop */
    for (i = 0; i < 3; i++)
    {
        perm[i][0] = 'r';
        perm[i][1] = 'w';
        perm[i][2] = '-';
        perm[i][3] = '\0';
    }

    /* Modify permissions */
    perm[1][1] = '-';  // Group: r--
    perm[2][0] = 'r';  // Others: r--
    perm[2][1] = '-';

    printf("Linux File Access Permissions\n\n");

    for (i = 0; i < 3; i++)
    {
        printf("%s permissions: %s\n", users[i], perm[i]);
    }

    return 0;
}

