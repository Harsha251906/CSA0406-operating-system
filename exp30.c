#include <stdio.h>
#include <windows.h>

DWORD tid1, tid2;

// Thread function
DWORD WINAPI myThread(LPVOID param)
{
    printf("Thread running with ID: %ld\n", GetCurrentThreadId());

    // Thread exit
    ExitThread(0);
    return 0;
}

int main()
{
    HANDLE t1, t2;

    // Create threads
    t1 = CreateThread(NULL, 0, myThread, NULL, 0, &tid1);
    t2 = CreateThread(NULL, 0, myThread, NULL, 0, &tid2);

    // Join threads (wait for completion)
    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    // Thread equal (ID comparison)
    if(tid1 == tid2)
        printf("Threads are equal\n");
    else
        printf("Threads are NOT equal\n");

    printf("Main thread exiting\n");
    return 0;
}

