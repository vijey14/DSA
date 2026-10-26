#include<stdio.h>
#include<stdlib.h>

int main(){
    int **a, **b, **c, rows1, cols1, rows2, cols2;
    int i, j, k;

    printf("Enter the no. of rows for the first matrix: \n");
    scanf("%d", &rows1);

    printf("Enter the no. of cols for the first matrix: \n");
    scanf("%d", &cols1);

    printf("Enter the no. of rows for the second matrix: \n");
    scanf("%d", &rows2);

    printf("Enter the no. of cols for the second matrix: \n");
    scanf("%d", &cols2);

    if(cols1 != rows2){
        printf("Multiplication is not possible");
        return 1;
    }

    a = malloc(rows1 * sizeof(int *));
    for(i = 0 ; i < rows1 ; i++){
        a[i] = malloc(cols1 * sizeof(int));
    }

    b = malloc(rows2 * sizeof(int *));
    for(i = 0; i < rows2 ; i++){
        b[i] = malloc(cols2 * sizeof(int));
    }

    c = malloc(rows1 * sizeof(int *));
    for(i = 0 ; i < rows1; i++){
        c[i] = malloc(cols2 * sizeof(int));
    }

    printf("Enter the first matrix data : ");
    for(i = 0 ; i < rows1; i++){
        for(j = 0; j < cols1; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the second matrix data : ");
    for(i = 0 ; i < rows2; i++){
        for(j = 0; j < cols2; j++){
            scanf("%d", &b[i][j]);
        }
    }

    for(i = 0 ; i < rows1; i++){
        for(j =0; j < cols2; j++){
            c[i][j] = 0;
            for(k =0; k < cols1; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("The matrix multiplication is: \n");
    for(i = 0; i < rows1; i++){
        for(j = 0; j <cols2; j++){
            printf("%d \t", c[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < rows1 ; i++){
        free(a[i]);
    }free(a);

    for(i = 0; i < rows2 ; i++){
        free(b[i]);
    }free(b);

    for(i = 0; i < rows1 ; i++){
        free(c[i]);
    }free(c);




}