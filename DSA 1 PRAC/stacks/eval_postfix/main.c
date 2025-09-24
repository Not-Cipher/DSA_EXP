#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100
int stack[MAX]; 
char postfix[MAX], infix[MAX];
int top = -1;
void push(char symbol){
    if(top == MAX-1){
        printf("Overflow!!");
    } else {
        top++;
        stack[top] = symbol;
    }
}

char pop(){
    if(top == -1){
        printf("underflow!!");
        return '\0';
    } else {
        char data = stack[top];
        top--;
        return data;
    }
}

int precedence(char symbol){
    switch(symbol){
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default: 
            return 0;
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    } else {
        return 0;
    }
}

void inToPost(){
    char symbol, next;
    int j=0;
    for(int i=0; i<strlen(infix); i++){
        symbol = infix[i];
        switch(symbol){
            case '(':
                push(symbol);
                break;
            case ')':
                while((next=pop()) != '('){
                    postfix[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && precedence(stack[top]) >= precedence(symbol)){
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
        }
    }
    while(!isEmpty()){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("postfix expression: %s\n", postfix);
}

int post_eval(){
    for (int i=0; i<strlen(postfix); i++){
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            push(postfix[i]-'0');
        } else {
            int a = pop();
            int b = pop();
            switch(postfix[i]){
                case '+':
                    push(b+a);
                    break;
                case '-':
                    push(b-a);
                    break;
                case '*':
                    push(b*a);
                    break;
                case '/':
                    push(b/a);  
                    break;
                case '^':
                    push(pow(b, a));
                    break;
            }
        }
    } return pop();
}

int main(){
    int result;
    printf("Enter the infix expression: ");
    gets(infix);

    inToPost();

    result = post_eval();
    printf("Result: %d\n", result);
    return 0;
}