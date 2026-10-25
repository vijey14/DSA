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

int searchElement(int target)
{
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->data == target)
        {
            printf("\nPosition is: %d\n", position);
            return position;
        }

        position++;
        temp = temp->next;
    }

    return -1;
}

void insertSorted(int value)
{
    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    // Case 1: Empty list or insert at the beginning
    if (head == NULL || value <= head->data)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Find the correct position
    while (temp->next != NULL && temp->next->data < value)
    {
        temp = temp->next;
    }

    // Case 3: Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;
}

void deletePosition(int position)
{
    if (position < 1 || head == NULL)
    {
        return;
    }

    if (position == 1)
    {
        struct Node *nodeToDelete = head;
        head = head->next;
        free(nodeToDelete);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void deleteNode(int value)
{
    if (head == NULL)
    {
        return;
    }

    if (head->data == value)
    {
        struct Node *nodeToDelete = head;
        head = head->next;
        free(nodeToDelete);
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next != NULL)
    {
        struct Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }
}

void deleteOccurance(int target){
    struct Node* temp = head;
    struct Node* del = NULL;

    if(head -> data == target){
        del = head;
        head = head -> next;
        free(del);
    }
    while(temp -> next != NULL){
        if (temp -> next -> data == target){
            del = temp -> next;
            temp -> next = del -> next;
            free(del);
        }
        else{
            temp = temp -> next;
        }
    }
}

void FreeList(){
    struct Node* temp;
    while (head != NULL){
        temp = head;
        head = head -> next;
        free(temp);
        temp = head;
    }
}


void reverseList(void){
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;

    }
    head = prev;

}


int main(void)
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);
    reverseList();

    

    countNode();
    traverse();
    searchElement(20);

    return 0;
}