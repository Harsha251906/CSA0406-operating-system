#include <stdio.h>
#include <windows.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

HANDLE empty, full, mutex;

// Producer thread
DWORD WINAPI producer(LPVOID param)
{
    int item, i;

    for(i = 1; i <= 5; i++)
    {
        item = i;

        WaitForSingleObject(empty, INFINITE);
        WaitForSingleObject(mutex, INFINITE);

        buffer[in] = item;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        ReleaseSemaphore(mutex, 1, NULL);
        ReleaseSemaphore(full, 1, NULL);

        Sleep(500);
    }
    return 0;
}

// Consumer thread
DWORD WINAPI consumer(LPVOID param)
{
    int item, i;

    for(i = 1; i <= 5; i++)
    {
        WaitForSingleObject(full, INFINITE);
        WaitForSingleObject(mutex, INFINITE);

        item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        ReleaseSemaphore(mutex, 1, NULL);
        ReleaseSemaphore(empty, 1, NULL);

        Sleep(500);
    }
    return 0;
}

int main()
{
    HANDLE p, c;

    // Create semaphores
    empty = CreateSemaphore(NULL, BUFFER_SIZE, BUFFER_SIZE, NULL);
    full  = CreateSemaphore(NULL, 0, BUFFER_SIZE, NULL);
    mutex = CreateSemaphore(NULL, 1, 1, NULL);

    // Create threads
    p = CreateThread(NULL, 0, producer, NULL, 0, NULL);
    c = CreateThread(NULL, 0, consumer, NULL, 0, NULL);

    // Wait for threads to finish
    WaitForSingleObject(p, INFINITE);
    WaitForSingleObject(c, INFINITE);

    return 0;
}

