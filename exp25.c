#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
    FILE *fp;
    struct stat info;
    DIR *d;
    struct dirent *dir;
    char ch;

    /* File open (fcntl simulation) */
    fp = fopen("sample.txt", "w+");
    fprintf(fp, "UNIX IO Calls");
    printf("File opened and written\n");

    /* File seek (lseek simulation) */
    fseek(fp, 0, SEEK_SET);
    ch = fgetc(fp);
    printf("First character using seek: %c\n", ch);
    fclose(fp);

    /* File status (stat simulation) */
    stat("sample.txt", &info);
    printf("File size: %ld bytes\n", info.st_size);

    /* Directory operations (opendir, readdir simulation) */
    d = opendir(".");
    printf("\nDirectory contents:\n");
    while((dir = readdir(d)) != NULL)
    {
        printf("%s\n", dir->d_name);
    }
    closedir(d);

    return 0;
}

