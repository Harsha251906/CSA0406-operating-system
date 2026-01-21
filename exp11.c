#include <stdio.h>
#include <windows.h>

// Thread function 1
DWORD WINAPI threadFunc1(LPVOID param)
{
	int i;
    for( i = 0; i < 5; i++)
        printf("Thread 1: %d\n", i);
    return 0;
}

// Thread function 2
DWORD WINAPI threadFunc2(LPVOID param)
{
	int i;
    for(i = 0; i < 5; i++)
        printf("Thread 2: %d\n", i);
    return 0;
}

int main()
{
    HANDLE t1, t2;

    // Create threads
    t1 = CreateThread(NULL, 0, threadFunc1, NULL, 0, NULL);
    t2 = CreateThread(NULL, 0, threadFunc2, NULL, 0, NULL);

    // Wait for threads to finish
    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    printf("Both threads finished execution.\n");
    return 0;
}

