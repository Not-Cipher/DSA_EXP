#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int top = -1;
char stack[MAX];
char infix[MAX], postfix[MAX];

void push(char x){
    if(top == MAX-1){
        printf("Overflow!!\n");
    } else {
        top++;
        stack[top] = x;
    }
}

char pop(){
    if(top == -1){
        printf("Underflow!!\n");
        return '\0';
    } else {
        return stack[top--];
    }
}
int isEmpty(){
    if(top == -1){
        return 1;
    } else {
        return 0;
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
                while((next=pop()) != '(')
                    postfix[j++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && precedence(stack[top]) >= precedence(symbol)){
                    postfix[j++] = pop();}
                    push(symbol);
                    break;
            default:
                postfix[j++] = symbol;
                
        }
    } while(!isEmpty()){
        postfix[j++] = pop();

    } postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main(){
    printf("Enter the infix expression: ");
    gets(infix);
    inToPost();
}