#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct queue {
    int data[SIZE];
    int front, rear;
} q = { .front = -1, .rear = -1 };

void enqueue(int item) {
    if (q.rear == SIZE - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q.front == -1) q.front = 0;
    q.data[++q.rear] = item;
}

int dequeue() {
    if (q.front == -1 || q.front > q.rear) {
        printf("Queue Underflow!\n");
        return -1;
    }
    return q.data[q.front++];
}

int findMax() {
    if (q.front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    int max = q.data[q.front];
    for (int i = q.front; i <= q.rear; i++) {
        if (q.data[i] > max) max = q.data[i];
    }
    return max;
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(3);
    enqueue(7);
    printf("Max Element: %d\n", findMax());
    return 0;
}
