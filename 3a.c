#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void removeDuplicates() {
    struct node* current = head;
    while (current != NULL) {
        struct node* runner = current;
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                struct node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

void display() {
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert(5);
    insert(4);
    insert(5);
    insert(3);
    display();
    removeDuplicates();
    display();
    return 0;
}
