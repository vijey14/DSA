// lets find prime numbers from 1 to n using sieve of eratosthenes

#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int is_Prime[n+1];

    for(int i = 0; i <=n; i++){
        is_Prime[i] = 1;     // we intialize all numbers as prime
    }

    is_Prime[0] = 0; // 0 is not prime
    is_Prime[1] = 0; // 1 is not prime

    for(int num = 2; num <= n*n; num++){
        if(is_Prime[num] == 1){
            for(int j = num*num; j <= n; j += num){ // here num*num is the first multiple of num that is greater than or equal to num*num
                is_Prime[j] = 0; // mark all multiples of num as not prime
            }
        }
    }
    printf("Prime numbers from 1 to %d are: ", n);  
    for(int i = 2; i <= n; i++){
        if(is_Prime[i] == 1){
            printf("%d ", i);
        }
    }
    return 0;


}