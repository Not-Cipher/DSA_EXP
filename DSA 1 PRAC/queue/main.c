#include<stdio.h>

int front = -1, rear = -1;
int queue[5];

void enqueue(int x){
    if(front == -1 && rear == -1){
        front = 0; rear = 0;
        queue[rear] = x;
    } else if(rear == 4){
        printf("queue overflow\n");
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("queue is empty\n");
    } else if(front == rear){
        front = -1; rear = -1;
    } else {
        front++;
    }
}

void getfront(){
    if(front == -1 && rear == -1){
        printf("queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void getrear(){
    if(front == -1 && rear == -1){
        printf("queue is empty\n");
    } else {
        printf("Rear element: %d\n", queue[rear]);
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("queue is empty\n");
    } else {
        printf("Queue: ");
        for(int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, x;
    while(1){
        printf("\n1. enqueue\n2. dequeue\n3. get front\n4. get rear\n5. display\n6. exit\n");
        printf("Enter choice: ");
        if(scanf("%d", &choice) != 1) return 0;
        switch(choice){
            case 1:
                printf("Enter value: ");
                if(scanf("%d", &x) != 1) return 0;
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                getfront();
                break;
            case 4:
                getrear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
