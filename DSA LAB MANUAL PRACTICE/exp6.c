#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;


void insert_at_beginning(int value){
    struct Node* newNode = malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory allocation failed");
        return;
    }

    newNode -> data = value;
    newNode -> prev = NULL;
    newNode -> next = head;
    if(head != NULL){
        head -> prev = newNode;
    }

    head = newNode;

}

void traverse(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp-> data);
        temp = temp -> next;
    }
    printf("\n");
}


int main() {
int n, data, i;

printf("Enter the number of elements: ");
scanf("%d", &n);

printf("Enter the elements of the doubly linked list: ");

for (i = 0; i < n; i++) {
    scanf("%d", &data);
    insert_at_beginning(data);
}

traverse();

return 0;

}