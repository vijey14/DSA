#include<stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value){
    if(top == MAX -1){
        printf("Overflow");
        return;
    }
    top++;
    stack[top] = value;
    printf("Element successfully pushed \n");

}

void pop(){
    if (top == -1){
        printf("Underflow");
        return;
    }
    int value = stack[top];
    top--;
    printf("Removed the element : %d \n", value);
}

void display(){
    if(top == -1){
        printf("Stack is empty");
        return;
    }
    printf("Stack: ");
    for (int i = top; i >= 0; i--){
        printf("%d \t", stack[i]);
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
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
