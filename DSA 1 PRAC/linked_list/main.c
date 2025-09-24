#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

void count_of_nodes(struct node *head){
    int count = 0;
    if(head == NULL){
        printf("list is empty\n");
        struct node *ptr = NULL;}
    else{
        struct node *ptr = head;
        while(ptr != NULL){
            count++;
            ptr = ptr->link;
    }
    } printf("%d\n", count);
}

int main(){

    
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    struct node *current = NULL;
    current  = (struct node *)malloc(sizeof(struct node));
    current -> data = 34; 
    current -> link= NULL;
    head -> link = current;

    current = (struct node *)malloc(sizeof(struct node));
    current -> data = 23;
    current -> link = NULL;
    head->link->link = current;

    count_of_nodes(head);
    return 0;


}



