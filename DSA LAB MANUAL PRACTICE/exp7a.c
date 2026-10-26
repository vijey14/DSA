#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};


struct Node* top = NULL;

void push(int value){
    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode == NULL){
        printf("Memory allocation failed");
        return;
    }

    newNode -> data = value;
    newNode -> next = top;
    top = newNode;

    printf("Element is added successfully");
}

void pop(){
    if(top == NULL){
        printf("UnderFlow");
        return;
    }

    struct Node* temp = top;
    printf("Removed element is: %d", temp -> data);
    top = top -> next;
    free(temp);


}


void display(){
    if(top == NULL){
        printf("Stack is empty");
        return;
    }
    struct Node* temp = top;
    printf("\n List : ");

    while(temp != NULL){
        printf("%d \t", temp -> data);
        temp = temp -> next;
        
    }
}

void freeStack(){
    struct Node* temp;
    while(top != NULL){
        temp = top;
        top = top -> next;
        free(temp);

    }
}


int main(){
    int choice, value;

    do{
        printf("\nSTACK USING LINKED LIST\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. FreeStack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push:");
            scanf("%d", &value);
            push(value);
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            freeStack();
            break;
        case 5:
            printf("Existing");
            break;
        default:
            printf("Invalid Value");
            break;
        }
    }while(choice != 5);
    freeStack();
}