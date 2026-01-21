#include <stdio.h>

struct emp
{
    int id;
    char name[20];
    float salary;
};

int main()
{
    FILE *fp;
    struct emp e;
    int choice, n, i, pos;

    fp = fopen("employee.dat", "rb+");
    if(fp == NULL)
        fp = fopen("employee.dat", "wb+");

    while(1)
    {
        printf("\n1.Add Employee");
        printf("\n2.Display All");
        printf("\n3.Search by Record Number");
        printf("\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter number of employees: ");
            scanf("%d", &n);

            for(i = 0; i < n; i++)
            {
                printf("Enter ID, Name, Salary: ");
                scanf("%d %s %f", &e.id, e.name, &e.salary);
                fwrite(&e, sizeof(e), 1, fp);
            }
        }
        else if(choice == 2)
        {
            rewind(fp);
            printf("\nID\tName\tSalary\n");

            while(fread(&e, sizeof(e), 1, fp))
                printf("%d\t%s\t%.2f\n", e.id, e.name, e.salary);
        }
        else if(choice == 3)
        {
            printf("Enter record number: ");
            scanf("%d", &pos);

            fseek(fp, (pos - 1) * sizeof(e), SEEK_SET);
            fread(&e, sizeof(e), 1, fp);

            printf("ID: %d\nName: %s\nSalary: %.2f\n",
                   e.id, e.name, e.salary);
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

    fclose(fp);
    return 0;
}

