#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int top = -1;
char stack[MAX];

int isEmpty(){
    if(top == -1)
    return 1;
    else return 0;
}
char pop(){
    if(top == -1){
        printf("Empty stack\n");
        return '\0';  // return null char if empty
    } else {
        return stack[top--];
    }
}

void push(char x){
    if(top == MAX-1){
        printf("Overflow!!");
    } else {
        top++;
        stack[top]= x;
    }
}

int match_char(char a, char b){
    if(a == '(' && b == ')')
    return 1;
    if(a == '{' && b == '}')
    return 1;
    if(a == '[' && b == ']')
    return 1;
    return 0;
    
}
int check_balance(char* s){
    for(int i=0; i<strlen(s); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            push(s[i]);
        } 
        if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(isEmpty()){
                printf("Invalid expr: r>l\n");
                return 0;
            } else {
                char temp = pop();
                if(!match_char(temp, s[i])){
                    printf("Invalid expr: r>l\n");
                    return 0;
                }
            }
            
        }
    }
    if(isEmpty()){
        printf("Balanced\n");
        return 1;
    } else {
        printf("Unbalanced\n");
        return 0;
    }

}

int main(){
    char expr[MAX];
    int balanced;
    printf("Enter the expression: ");
    gets(expr);
     balanced = check_balance(expr);

    return 0;


}
