#include <stdio.h>
#include <string.h>

#define MAX 5

// Simulated message queue
char message_queue[MAX][50];
int front = 0, rear = 0;

// Send message
void send_message(const char* msg)
{
    if (rear < MAX)
    {
        strcpy(message_queue[rear], msg);
        rear++;
        printf("Message sent: %s\n", msg);
    }
    else
        printf("Queue full! Cannot send message.\n");
}

// Receive message
void receive_message()
{
    if (front < rear)
    {
        printf("Message received: %s\n", message_queue[front]);
        front++;
    }
    else
        printf("Queue empty!\n");
}

int main()
{
    // Process 1 sends messages
    send_message("Hello from Process 1");
    send_message("OS Lab Message");

    // Process 2 receives messages
    receive_message();
    receive_message();
    receive_message(); // nothing left

    return 0;
}

