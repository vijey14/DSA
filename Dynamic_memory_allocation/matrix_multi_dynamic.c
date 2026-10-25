#include<stdio.h>
#include<stdlib.h>

int main(){
    int r1, c1, r2, c2, i, j, k;
    
    printf("Enter the rows and columns for first matrix : ");
    scanf("%d %d", &r1, &c1);

    printf("Enter the rows and columns for second matrix : ");
    scanf("%d %d", &r2, &c2);

    if (r2 != c1){
        printf("Invalid");
        return 0;
    }

    int **a = malloc(r1 * sizeof(int *));
    for(i = 0; i < r1 ; i++){
        a[i] = malloc (c1 * sizeof(int));
    }

    int **b = malloc(r2 * sizeof(int *));
    for(i = 0; i < r2 ; i++){
        b[i] = malloc (c2 * sizeof(int));
    }

    int **c = malloc(r1* sizeof(int *));
    for(i = 0; i < r1 ; i++){
        c[i] = malloc (c2 * sizeof(int));
    }

    for( i=0 ; i<r1 ; i++ ){
        for(j =0; j < c1; j++){
            printf("Enter the element %d for first matrix", i +1);
            scanf("%d",&a[i][j]);
        }
    }

    for( i=0 ; i<r2 ; i++ ){
        for(j =0; j < c2; j++){
            printf("Enter the element %d for second matrix", i +1);
            scanf("%d",&b[i][j]);
        }
    }

   for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            c[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

/*
PSEUDOCODE:

START

1. Check whether c1 == r2
   If not, matrix multiplication is not possible.

2. For i = 0 to r1-1
       For j = 0 to c2-1

           Set C[i][j] = 0

           For k = 0 to c1-1
               C[i][j] = C[i][j] + A[i][k] * B[k][j]

3. Print matrix C

END
*/
    for(i = 0; i < r1; i++){
        for(j = 0; j < c2; j++){
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    for(i=0; i < r1; i++ ){
        free(a[i]);
        free(c[i]);
    }

    for(i=0 ; i <r2; i++){
        free(b[i]);
    }

    free(a);
    free(b);
    free(c);

    

}

/*
    Dynamic Memory Allocation for 2D Matrix
    ----------------------------------------

    int **a
       |
       v
    +-------+
    |   *---|---------> [ a[0][0] a[0][1] ... ]
    +-------+
    |   *---|---------> [ a[1][0] a[1][1] ... ]
    +-------+
    |   *---|---------> [ a[2][0] a[2][1] ... ]
    +-------+
       ...
    
    Step 1:
        a = malloc(r1 * sizeof(int *));

        Creates an array of ROW pointers.

    Step 2:
        for(i = 0; i < r1; i++)
            a[i] = malloc(c1 * sizeof(int));

        Each a[i] points to a separate ROW of integers.

    
    Example: r1 = 3, c1 = 4

              a
              |
              v
        +-----+-----+-----+
        |  *  |  *  |  *  |
        +--|--+--|--+--|--+
           |     |     |
           v     v     v
        +---+---+---+---+
        | 1 | 2 | 3 | 4 |  ← a[0]
        +---+---+---+---+

        +---+---+---+---+
        | 5 | 6 | 7 | 8 |  ← a[1]
        +---+---+---+---+

        +---+---+---+---+
        | 9 |10 |11 |12 |  ← a[2]
        +---+---+---+---+

        a[i][j]
          ↓  ↓
          i  → ROW
          j  → COLUMN
*/