#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* head = NULL;

struct Node* CreateNode(int value){
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode -> data = value;
    newNode -> next = NULL;
    
    return newNode;
}

void insertNode(int value, int position){
    struct Node* newNode = CreateNode(value);

    if(position < 1){
        printf("Invaild position");
        free(newNode);
        return;
    }
    if(position == 1){
        newNode -> next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for(int i = 1; i < position -1 ; i++){
        temp = temp -> next;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void deleteNode(int position){
    if(head == NULL || position < 1){
        printf("List is empty");
        return;
    }
    struct Node* temp = head;
    for(int i = 1; i < position -1 ; i++){
        temp = temp -> next;
    }

    struct Node* del = NULL;
    del = temp -> next;
    temp -> next = del -> next;
    free(del);

}

void find(int value){
    struct Node* temp = head;
    int position = 1;

    while (temp != NULL){
        if(temp -> data == value){
            printf("Position : %d", position);
            return;
        }
        temp = temp -> next;
        position++;
    }

    printf("Element Not found");
}

void findPrevious(int value){
    struct Node* temp = head;

    if(temp == NULL || temp -> data == value){
        printf("No previous elements");
        return;
    }
    while(temp -> next != NULL){
        if(temp-> next-> data == value){
            printf("Previous element is: %d", temp -> data);
            return;
        }
        temp = temp -> next;
    }
    printf("No previous elements");
}
void printList(void)
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Elements in the list: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


int main(void)
{
    int choice, value, position;

    do
    {
        printf("\nImplementation of Linked List\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Find\n");
        printf("4. Find Previous\n");
        printf("5. Print List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &position);

                insertNode(value, position);
                printList();
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);

                deleteNode(position);
                printList();
                break;

            case 3:
                printf("Enter element to find: ");
                scanf("%d", &value);

                find(value);
                break;

            case 4:
                printf("Enter element: ");
                scanf("%d", &value);

                findPrevious(value);
                break;

            case 5:
                printList();
                break;

            case 6:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}