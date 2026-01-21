#include <stdio.h>
#include <windows.h>

HANDLE mutex;
int shared = 0;

// Thread function
DWORD WINAPI process(LPVOID param)
{
    int i;

    for(i = 0; i < 5; i++)
    {
        WaitForSingleObject(mutex, INFINITE);

        shared++;
        printf("Process %d updated shared value to %d\n",
               (int)(size_t)param, shared);

        ReleaseMutex(mutex);
        Sleep(500);
    }
    return 0;
}

int main()
{
    HANDLE p1, p2;

    // Create mutex
    mutex = CreateMutex(NULL, FALSE, NULL);

    // Create threads (processes)
    p1 = CreateThread(NULL, 0, process, (LPVOID)1, 0, NULL);
    p2 = CreateThread(NULL, 0, process, (LPVOID)2, 0, NULL);

    // Wait for both threads to finish
    WaitForSingleObject(p1, INFINITE);
    WaitForSingleObject(p2, INFINITE);

    printf("Final shared value: %d\n", shared);
    return 0;
}

