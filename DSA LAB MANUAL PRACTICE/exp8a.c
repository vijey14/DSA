#include<stdio.h>

#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value){
    if (rear == MAX -1){
        printf("Overflow");
        return;
    }
    if (front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Element successfully added");
}   

void dequeue(){
    if(front == -1){
        printf("UnderFlow");
        return;
    }
    int value = queue[front];
    printf("Deleted element: %d", value);
    if (front == rear){
        front = -1;
        rear = -1;
    }else{
        front++;
    }
    
}

void display(){
    if (front == -1){
        printf("queue is empty");
        return;
    }
    printf("Queue elements from front to rear:\n");
    for(int i = front; i <= rear ; i++){
        printf("%d \t", queue[i]);
    }

}

int main(){
    int choice, value;

    do{
        printf("\nQUEUE USING ARRAY\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case  1:
            printf("Enter the value: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2 :
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Existing the program");
            break;
        default:
            printf("Invalid choice");
        }
    }while(choice != 4);
    return 0;
}