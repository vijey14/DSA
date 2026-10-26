#include<stdio.h>

#define MAX 100
int list[MAX];

int n = 0;

void display(void);

void create(){
    printf("Enter how many elements to be added: ");
    scanf("%d", &n);

    if(n < 0 || n > MAX){
        printf("Invalid size");
        return;
    }

    printf("Enter array elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &list[i]);
    }

    display();
}


void insert(){
    int value, pos;

    if(n >= MAX){
        printf("List is Full");
        return;
    }

    printf("Enter the position: ");
    scanf("%d", &pos);

    printf("Enter the value: ");
    scanf("%d", &value);

    for(int i = n ; i > pos; i--){
        list[i] = list[i - 1];
    }

    list[pos] = value;
    n++;
    display();
}


void delete(){
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if(n == 0){
        printf("List is empty");
    }
    if(pos < 0 || pos > MAX){
        printf("Invalide position");
        return;
    }

    for(int i = pos; i < n - 1 ;i++){
        list[i] = list[i +1];
    }
    n--;

    
}
void display() {
    int i;

    printf("**********Elements in the array**********\n");

    for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");
}

void search(){
    int value, found = 0;
    printf("Enter the element to be searched: ");
    scanf("%d", &value);

    for(int i =0; i < n; i++){
        if(list[i] == value){
            found = 1;
            break;
        }


    }

    if(found == 1){
        printf("Element in list");
    }else{
        printf("Element not in list");
    }
}


int main() {
    int choice;

    while (1) {
        printf("\nArray Implementation of List\n");
        printf("1.Create\n");
        printf("2.Insert\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Search\n");
        printf("6.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                insert();
                break;

            case 3:
                delete();
                break;

            case 4:
                display();
                break;

            case 5:
                search();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
