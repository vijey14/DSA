#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    if(front == NULL){
        front = newNode;
        rear = newNode;
    }else{
        rear -> next = newNode;
        rear = newNode;
    }
    printf("Element added successfully");
}

void dequeue(){

    if(front == NULL){
        printf("Underflow");
        return;
    }
    struct Node* temp = front;
    printf("Element dequeued %d", temp -> data);

    front = front -> next;
    if(front == NULL){
        rear = NULL;
    }

    free(temp);


}

void display(){
    if(front == NULL){
        printf("Empty stack");
    }
    struct Node* temp = front;
    printf("Elements in the queue");
    while(temp != NULL){
        printf("%d \t", temp-> data);
        temp = temp -> next;
    }
}

void freeQueue(){
    struct Node* temp;
    
    while(front != NULL){
        temp = front;
        front = front -> next;
        free(temp);
    }
    rear = NULL;

}
int main()
{
int choice, value;

do
{
    printf("\nQUEUE USING LINKED LIST\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input\n");
        freeQueue();
        return 1;
    }

    switch (choice)
    {
        case 1:
            printf("Enter the registration number: ");

            if (scanf("%d", &value) != 1)
            {
                printf("Invalid input\n");
                freeQueue();
                return 1;
            }

            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting the program\n");
            break;

        default:
            printf("Invalid choice\n");
    }

} while (choice != 4);

freeQueue();

return 0;

}