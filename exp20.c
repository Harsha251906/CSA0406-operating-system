#include <stdio.h>
#include <windows.h>

HANDLE mutex, wrt;
int readcount = 0;
int data = 100;

// Reader thread
DWORD WINAPI reader(LPVOID param)
{
    int i;

    for(i = 0; i < 3; i++)
    {
        WaitForSingleObject(mutex, INFINITE);
        readcount++;
        if(readcount == 1)
            WaitForSingleObject(wrt, INFINITE);
        ReleaseSemaphore(mutex, 1, NULL);

        printf("Reader %d reads data = %d\n",
               (int)(size_t)param, data);
        Sleep(500);

        WaitForSingleObject(mutex, INFINITE);
        readcount--;
        if(readcount == 0)
            ReleaseSemaphore(wrt, 1, NULL);
        ReleaseSemaphore(mutex, 1, NULL);

        Sleep(500);
    }
    return 0;
}

// Writer thread
DWORD WINAPI writer(LPVOID param)
{
    int i;

    for(i = 0; i < 3; i++)
    {
        WaitForSingleObject(wrt, INFINITE);

        data += 10;
        printf("Writer writes data = %d\n", data);
        Sleep(500);

        ReleaseSemaphore(wrt, 1, NULL);
        Sleep(500);
    }
    return 0;
}

int main()
{
    HANDLE r1, r2, w1;

    // Create semaphores
    mutex = CreateSemaphore(NULL, 1, 1, NULL);
    wrt   = CreateSemaphore(NULL, 1, 1, NULL);

    // Create reader and writer threads
    r1 = CreateThread(NULL, 0, reader, (LPVOID)1, 0, NULL);
    r2 = CreateThread(NULL, 0, reader, (LPVOID)2, 0, NULL);
    w1 = CreateThread(NULL, 0, writer, NULL, 0, NULL);

    // Wait for completion
    WaitForSingleObject(r1, INFINITE);
    WaitForSingleObject(r2, INFINITE);
    WaitForSingleObject(w1, INFINITE);

    return 0;
}

