
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 20

char stk[MAX];
int top = -1;

// Check whether stack is empty
int isEmpty()
{
    return top == -1;
}

// Check whether stack is full
int isFull()
{
    return top == MAX - 1;
}

// Return top element
char peek()
{
    if (isEmpty())
        return '\0';

    return stk[top];
}

// Insert operator into stack
void push(char oper)
{
    if (isFull())
    {
        printf("Stack Full!\n");
        return;
    }

    top++;
    stk[top] = oper;
}

// Remove element from stack
char pop()
{
    if (isEmpty())
        return '\0';

    char ch = stk[top];
    top--;
    return ch;
}

// Check whether character is an operand
int checkIfOperand(char ch)
{
    return isalnum((unsigned char)ch);
}

// Return operator precedence
int precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
        case '%':
            return 2;

        case '^':
            return 3;

        default:
            return -1;
    }
}

// Convert infix expression to postfix
int convertInfixToPostfix(char *expression, char *postfix)
{
    int i, j = 0;

    top = -1;

    for (i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];

        // 1. If operand, add to postfix
        if (checkIfOperand(ch))
        {
            postfix[j++] = ch;
        }

        // 2. If opening bracket, push
        else if (ch == '(')
        {
            push(ch);
        }

        // 3. If closing bracket, pop until '('
        else if (ch == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                postfix[j++] = pop();
            }

            if (isEmpty())
                return -1;  // Mismatched bracket

            pop();  // Remove '('
        }

        // 4. If operator
        else if (precedence(ch) != -1)
        {
            while (!isEmpty() && peek() != '(' &&
                   (precedence(peek()) > precedence(ch) ||
                   (precedence(peek()) == precedence(ch) &&
                    ch != '^')))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // 5. Pop remaining operators
    while (!isEmpty())
    {
        if (peek() == '(')
            return -1;

        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    return j;
}

// Main function
int main()
{
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%19s", infix);

    int result = convertInfixToPostfix(infix, postfix);

    if (result == -1)
    {
        printf("Invalid expression!\n");
    }
    else
    {
        printf("Postfix expression: %s\n", postfix);
    }

    return 0;
}
