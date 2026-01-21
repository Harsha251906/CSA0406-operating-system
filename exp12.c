#include <stdio.h>
#include <windows.h>

#define N 5  // Number of philosophers

HANDLE forks[N];      // Mutexes representing forks
HANDLE threads[N];    // Philosopher threads

// Philosopher thread function
DWORD WINAPI philosopher(LPVOID num) {
    int id = (int)(size_t)num; // Philosopher ID
    int k;

    for(k = 0; k < 2; k++) { // Each philosopher eats twice
        // Pick left fork
        WaitForSingleObject(forks[id], INFINITE);
        // Pick right fork
        WaitForSingleObject(forks[(id + 1) % N], INFINITE);

        printf("Philosopher %d is eating.\n", id + 1);
        Sleep(500); // Simulate eating

        // Put down forks
        ReleaseMutex(forks[id]);
        ReleaseMutex(forks[(id + 1) % N]);

        printf("Philosopher %d is thinking.\n", id + 1);
        Sleep(500); // Simulate thinking
    }

    return 0;
}

int main() {
    int i;

    // Initialize forks (mutexes)
    for(i = 0; i < N; i++)
        forks[i] = CreateMutex(NULL, FALSE, NULL);

    // Create philosopher threads
    for(i = 0; i < N; i++)
        threads[i] = CreateThread(NULL, 0, philosopher, (LPVOID)(size_t)i, 0, NULL);

    // Wait for all threads to finish
    WaitForMultipleObjects(N, threads, TRUE, INFINITE);

    printf("Dining completed.\n");
    return 0;
}

