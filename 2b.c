#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct dequeue {
    struct node* front;
    struct node* rear;
} dq = { .front = NULL, .rear = NULL };

void insertFront(int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = dq.front;
    newNode->prev = NULL;
    if (dq.front != NULL) dq.front->prev = newNode;
    dq.front = newNode;
    if (dq.rear == NULL) dq.rear = newNode;
    printf("Inserted %d at the front.\n", item);
}

void insertRear(int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = NULL;
    newNode->prev = dq.rear;
    if (dq.rear != NULL) dq.rear->next = newNode;
    dq.rear = newNode;
    if (dq.front == NULL) dq.front = newNode;
    printf("Inserted %d at the rear.\n", item);
}

void deleteFront() {
    if (dq.front == NULL) {
        printf("Dequeue is empty.\n");
        return;
    }
    struct node* temp = dq.front;
    dq.front = dq.front->next;
    if (dq.front != NULL) dq.front->prev = NULL;
    else dq.rear = NULL;
    printf("Deleted %d from the front.\n", temp->data);
    free(temp);
}

void deleteRear() {
    if (dq.rear == NULL) {
        printf("Dequeue is empty.\n");
        return;
    }
    struct node* temp = dq.rear;
    dq.rear = dq.rear->prev;
    if (dq.rear != NULL) dq.rear->next = NULL;
    else dq.front = NULL;
    printf("Deleted %d from the rear.\n", temp->data);
    free(temp);
}

void displayDequeue() {
    struct node* temp = dq.front;
    printf("Dequeue Elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertFront(10);
    insertRear(20);
    insertFront(5);
    displayDequeue();
    deleteFront();
    deleteRear();
    displayDequeue();
    return 0;
}
