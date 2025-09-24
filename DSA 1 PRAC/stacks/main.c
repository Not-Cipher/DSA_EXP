#include<stdio.h>
#define MAX 100
int top = -1;
int stack[MAX];

void push(int x){
    if(top == MAX -1){
        printf("stack overflow\n");
    } else {
        top++;
        stack[top] = x;
    }
}

void pop(){
    if(top == -1){
        printf("stack is empty");
    } else {
        top--;
    }
}

void peek(){
    if(top == -1){
        printf("stack is empty");

    } else {
        printf("%d ", stack[top]);
    }
}

void display(){
    if(top == -1){
        printf("Empty stack");
    } else {
        printf("\n");
        for(int i =top ; i>=0; i--){
            printf("%d ", stack[i]);
        } printf("\n");
    }
}

int main(){
    int choice, x;
    while(1){
        printf("\nStack Menu\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. display\n");
        printf("5. exit\n");
        printf("Enter choice: ");
        if(scanf("%d", &choice) != 1) return 0;

        if(choice == 1){
            printf("Enter value: ");
            if(scanf("%d", &x) != 1) return 0;
            push(x);
        } else if(choice == 2){
            pop();
        } else if(choice == 3){
            peek();
        } else if(choice == 4){
            display();
        } else if(choice == 5){
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
