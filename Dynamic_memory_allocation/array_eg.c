#include <stdio.h>
#include <stdlib.h>

int main (){
    int n = 5;
    
    /*printf("Enter the size of the array: ");
    scanf("%d", &n);
    */

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

    // Now, let's resize the array to double its original size with realloc

    int *temp = realloc(arr, 2 * n * sizeof(int)); // resize the array to double its original size
    if(temp == NULL) { // check if memory reallocation was successful
        printf("Memory reallocation failed!\n");
        free(arr); // free the original memory if reallocation fails
        return 1; // exit the program with an error code
    }
    arr = temp; // update the pointer to the new memory location
    n = 2 * n; // update the size of the array
    for(int i = n/2; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]); // read new elements into the resized array
    }
    for(int i = 0; i < n; i++){
        printf("Element %d: %d\n", i + 1, arr[i]); // print all elements of the resized array
    }


    free(arr); // free the dynamically allocated memory
    return 0; // exit the program successfully

}

/*
Remember this table:

                    malloc	                        calloc
Arguments	           1	                            2
Purpose	            Allocate memory	            Allocate array-like memory
Initialization  No zero initialization	            Zero initialized
Example	        malloc(5 * sizeof(int))	        calloc(5, sizeof(int))




malloc()
   ↓
Rent memory

Use memory
   ↓

free()
   ↓
Return memory



             Dynamic Memory
                   │
       ┌───────────┼───────────┐
       ↓           ↓           ↓
    malloc       calloc      realloc
       │           │           │
    Allocate     Allocate     Resize
       │        + zero init
       │
       └───────────┬───────────
                   ↓
                  free
                   │
              Release memory


❌ Forgetting stdlib.h

You need:

#include <stdlib.h>

for malloc, calloc, realloc, and free
*/


