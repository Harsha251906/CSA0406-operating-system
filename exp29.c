#include <stdio.h>
#include <windows.h>

int buffer = 0;
int full = 0;

DWORD WINAPI producer(LPVOID lpParam)
{
    int i;

    for(i = 1; i <= 5; i++)
    {
        while(full == 1);   // wait
        buffer = i;
        printf("Producer produced: %d\n", buffer);
        full = 1;
        Sleep(500);
    }
    return 0;
}

DWORD WINAPI consumer(LPVOID lpParam)
{
    int i;

    for(i = 1; i <= 5; i++)
    {
        while(full == 0);   // wait
        printf("Consumer consumed: %d\n", buffer);
        full = 0;
        Sleep(500);
    }
    return 0;
}

int main()
{
    HANDLE h1, h2;

    h1 = CreateThread(NULL, 0, producer, NULL, 0, NULL);
    h2 = CreateThread(NULL, 0, consumer, NULL, 0, NULL);

    WaitForSingleObject(h1, INFINITE);
    WaitForSingleObject(h2, INFINITE);

    return 0;
}

