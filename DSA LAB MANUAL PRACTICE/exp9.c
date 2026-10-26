#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value){
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }

    stack[++top] = value;
}

int pop(){
    if (top == -1) {
        printf("Invalid expression\n");
        exit(1);
    }
    return stack[top--];
}

int main(){
    char expression[200];
    char *token;
    char *end;
    int o1, o2, result;

    printf("Enter postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    token = strtok(expression, "\t \n");
    while(token != NULL){
        long value = strtol(token, &end, 10);
        if(*end == '\0'){
            push((int)value);
        }
        else{
            
            o2 = pop();
            o1 = pop();

            switch (token[0])
            {
            case '+':
                result = o1 + o2;
                break;
            case '-':
                result = o1 - o2;
                break;
            case '*':
                result = o1 * o2;
                break;

            case '/':
                result = o1 / o2;
                   break;

            default:
                printf("Invalid operator\n");
                return 1;


            }
            push(result);
        }
        token = strtok(NULL, "\t \n");
    }
    result = pop();
    printf("Result: %d\n", result);
    return 0;


}