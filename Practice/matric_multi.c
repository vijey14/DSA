#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[100][100], b[100][100], c[100][100], r1, c1, r2, c2, i, j, k;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    if(c1 != r2){
        printf("Invaild cant multiplu");
        return 0;
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

    for(i =0; i<r1; i++){
        for(j=0; j <c2 ; j++){
            c[i][j]= 0;
            for(k =0; k<c2 ; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for( i=0 ; i<r2 ; i++ ){
        for(j =0; j < c1; j++){
            printf("%d \t", c[i][j]);
        }
        printf("\n");
    }



}