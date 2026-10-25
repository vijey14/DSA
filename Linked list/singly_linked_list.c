#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void traverse(void)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void countNode(void){
    struct Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    printf("No of node is: %d \n", count);
}

int searchElement(int target){
    struct Node* temp = head;
    int position = 0;
    while(temp != NULL){
        if(temp -> data == target){
            printf("\n Position is: %d", position + 1);
        }
        position++;
        temp = temp -> next;
    }
    return -1;
    
}

int main(void)
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    countNode();
    traverse();
    searchElement(20);

    return 0;
}