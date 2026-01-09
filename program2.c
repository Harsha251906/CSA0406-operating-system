#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd1, fd2;
    char buffer[100];
    int n;

    fd1 = open("source.txt", O_RDONLY);
    fd2 = open("dest.txt", O_WRONLY | O_CREAT, 0644);

    while ((n = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        write(fd2, buffer, n);
    }

    close(fd1);
    close(fd2);

    printf("File copied successfully\n");
    return 0;
}
