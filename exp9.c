#include <stdio.h>

// Shared memory (global variable)
int shared_data = 0;

int main()
{
    printf("Process 1 writing to shared memory...\n");
    shared_data = 100;

    printf("Process 2 reading from shared memory...\n");
    printf("Data read: %d\n", shared_data);

    return 0;
}

