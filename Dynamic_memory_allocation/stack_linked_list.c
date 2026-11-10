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
    newNode -> data = value;
    if(top == NULL){
        newNode -> next = NULL;
        return;
    }
    newNode -> next = top;
    top = newNode;
}

void pop(){
    if(top == NULL){
        printf("Underflow");
        return;
    }
    struct Node* temp =  top;
    printf("Removed Element is: %d", &temp -> data);
    top = top -> next;
    free(temp);
}

void display(){
    struct Node* temp = top;
    while(temp != NULL){
        printf("%d \t",&temp -> data);
        temp = temp -> next;
    }

}

void freeStack(){
    struct Node* temp;
    while(temp != NULL){
        temp = top;
        top = top -> next;
        free(temp);
    }
}

int main(void)
{
    int choice, value;

    do
    {
        printf("\nSTACK USING ARRAY\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program\n");
                freeStack();
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
    freeStack();
}
