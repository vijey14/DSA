#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Allocate memory
    int *arr = malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Release memory
    free(arr);
    arr = NULL;

    return 0;
}

/*             Start
               ↓
        Ask number of elements
               ↓
             n = 5
               ↓
           malloc()
               ↓
      ┌─────────────────┐
      │ 5 × sizeof(int) │
      └─────────────────┘
               ↓
      ┌────┬────┬────┬────┬────┐
      │    │    │    │    │    │
      └────┴────┴────┴────┴────┘
               ↓
          Fill values
               ↓
          Use the array
               ↓
             free()
               ↓
              End
*/