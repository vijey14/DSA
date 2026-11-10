
#include <stdio.h>
#include <string.h>

#define MAX 100

char stk[MAX];
int top = -1;

// Check whether stack is empty
int isEmpty()
{
    return top == -1;
}

// Push opening bracket into stack
void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    stk[++top] = ch;
}

// Pop element from stack
char pop()
{
    if (isEmpty())
        return '\0';

    return stk[top--];
}

// Check whether brackets match
int match(char ch1, char ch2)
{
    if (ch1 == ')' && ch2 == '(')
        return 1;

    else if (ch1 == ']' && ch2 == '[')
        return 1;

    else if (ch1 == '}' && ch2 == '{')
        return 1;

    else
        return 0;
}

// Check whether expression is balanced
int balance(char *str)
{
    int i;

    top = -1;

    for (i = 0; i < strlen(str); i++)
    {
        // If opening bracket, push into stack
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(str[i]);
        }

        // If closing bracket
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (top == -1)
                return 0;

            else if (!match(str[i], pop()))
                return 0;
        }
    }

    // Check whether stack is empty
    if (top == -1)
        return 1;

    else
        return 0;
}

// Main function
int main()
{
    char str[MAX];

    printf("Enter an expression: ");
    scanf("%99s", str);

    if (balance(str))
        printf("Expression is Balanced.\n");

    else
        printf("Expression is Unbalanced.\n");

    return 0;
}
