#include <stdio.h>
#define MAX 10

int Queue[MAX];
int front = -1;
int rear  = -1;

int enqueue(int data) {
    if ((front == 0 && rear == MAX - 1) || (rear == front - 1)) {
        printf("Queue is full.\n");
        return 0;
    } else if (front == -1) {         // First element
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;                     // Wrap around
    } else {
        rear++;
    }
    Queue[rear] = data;
    return 1;
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return 0;
    }
    int data = Queue[front];

    if (front == rear) {              // Only one element
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    return data;
}

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (rear == front - 1));
}

int isEmpty() {
    return (front == -1);
}

int checkFront() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    return Queue[front];
}

int checkRear() {
    if (rear == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    return Queue[rear];
}

int size() {
    if (front == -1) return 0;
    if (rear >= front) return rear - front + 1;
    return (MAX - front) + (rear + 1);
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", Queue[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", Queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", Queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    do {
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check Front\n");
        printf("4. Check Rear\n");
        printf("5. Check if Queue is Full\n");
        printf("6. Check if Queue is Empty\n");
        printf("7. Get Queue Size\n");
        printf("8. Display Queue\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value) printf("Dequeued: %d\n", value);
                break;
            case 3:
                value = checkFront();
                if (value != -1) printf("Front element: %d\n", value);
                break;
            case 4:
                value = checkRear();
                if (value != -1) printf("Rear element: %d\n", value);
                break;
            case 5:
                printf(isFull() ? "Queue is FULL.\n" : "Queue is NOT full.\n");
                break;
            case 6:
                printf(isEmpty() ? "Queue is EMPTY.\n" : "Queue is NOT empty.\n");
                break;
            case 7:
                printf("Current queue size: %d\n", size());
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 9);

    return 0;
}
