#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[50];
    struct Node* next;
} Node;

Node *top = NULL;          
Node *front = NULL, *rear = NULL;

void push(char *item) {    
    Node *n = malloc(sizeof(Node));
    strcpy(n->data, item);
    n->next = top;
    top = n;
}

void pop() {
    if (!top) { printf("Undo stack empty\n"); return; }
    Node *temp = top;
    printf("Undo: %s removed\n", top->data);
    top = top->next;
    free(temp);
}

void displayStack() {
    Node *t = top;
    if (!t) { printf("No actions to undo\n"); return; }
    printf("Editor Actions:\n");
    while (t) {
        printf("%s\n", t->data);
        t = t->next;
    }
}

void enqueue(char *name) { 
    Node *n = malloc(sizeof(Node));
    strcpy(n->data, name);
    n->next = NULL;
    if (!rear) front = rear = n;
    else { rear->next = n; rear = n; }
}

void dequeue() {
    if (!front) { printf("No customers in queue\n"); return; }
    Node *temp = front;
    printf("Serving %s\n", front->data);
    front = front->next;
    if (!front) rear = NULL;
    free(temp);
}

void displayQueue() {
    Node *t = front;
    if (!t) { printf("No customers waiting\n"); return; }
    printf("Customer Queue:\n");
    while (t) {
        printf("%s\n", t->data);
        t = t->next;
    }
}

int main() {
    int choice;
    char input[50];

    do {
        printf("\n1.Push (Editor Action)\n2.Pop (Undo)\n3.Display Stack\n");
        printf("4.Enqueue (Customer)\n5.Dequeue (Serve)\n6.Display Queue\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1: printf("Enter action: "); gets(input); push(input); break;
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4: printf("Enter customer name: "); gets(input); enqueue(input); break;
            case 5: dequeue(); break;
            case 6: displayQueue(); break;
        }
    } while (choice != 7);
    return 0;
}
