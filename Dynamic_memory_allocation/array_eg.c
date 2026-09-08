#include <stdio.h>
#include <stdlib.h>

int main (){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int)); // dynamically allocate memory for an array of size n

    if(arr == NULL) { // check if memory allocation was successful
        printf("Memory allocation failed!\n");
        return 1; // exit the program with an error code
    }

    for(int i =0 ; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]); // read elements into the array
    }
    for(int i = 0; i < n; i++){
        printf("Element %d: %d\n", i + 1, arr[i]); // print the elements of the array
    }

    free(arr); // free the dynamically allocated memory
    return 0; // exit the program successfully

}