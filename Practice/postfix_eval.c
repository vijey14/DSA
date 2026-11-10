
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXCOLS 80

// Stack structure
struct stack
{
    int top;
    double items[MAXCOLS];
};

// Function declarations
double eval(char exp[]);
double pop(struct stack *s);
void push(struct stack *s, double value);
int empty(struct stack *s);
int isdigit(char sym);
double oper(int sym, double op1, double op2);

// Main function
int main()
{
    char expr[MAXCOLS];
    int position = 0;

    printf("Enter postfix expression: ");

    while ((expr[position++] = getchar()) != '\n')
    {
        if (position >= MAXCOLS - 1)
            break;
    }

    expr[--position] = '\0';

    printf("\nThe original postfix expression is: %s", expr);

    printf("\nResult = %.2lf\n", eval(expr));

    return 0;
}

// Check whether stack is empty
int empty(struct stack *s)
{
    return s->top == -1;
}

// Push element into stack
void push(struct stack *s, double value)
{
    if (s->top == MAXCOLS - 1)
    {
        printf("Stack Overflow!\n");
        exit(1);
    }

    s->items[++(s->top)] = value;
}

// Pop element from stack
double pop(struct stack *s)
{
    if (empty(s))
    {
        printf("Stack Underflow!\n");
        exit(1);
    }

    return s->items[(s->top)--];
}

// Check whether character is a digit
int isdigit(char sym)
{
    return (sym >= '0' && sym <= '9');
}

// Evaluate postfix expression
double eval(char exp[])
{
    int c, position;
    double opnd1, opnd2, value;

    struct stack opndstk;
    opndstk.top = -1;

    for (position = 0; (c = exp[position]) != '\0'; position++)
    {
        if (c == ' ')
            continue;

        if (isdigit(c))
        {
            // Convert character into number
            push(&opndstk, (double)(c - '0'));
        }
        else
        {
            // Operator
            opnd2 = pop(&opndstk);
            opnd1 = pop(&opndstk);

            value = oper(c, opnd1, opnd2);

            push(&opndstk, value);
        }
    }

    return pop(&opndstk);
}

// Perform arithmetic operation
double oper(int symb, double op1, double op2)
{
    switch (symb)
    {
        case '+':
            return op1 + op2;

        case '-':
            return op1 - op2;

        case '*':
            return op1 * op2;

        case '/':
            if (op2 == 0)
            {
                printf("Division by zero error!\n");
                exit(1);
            }
            return op1 / op2;

        case '$':
            return pow(op1, op2);

        default:
            printf("Illegal operation!\n");
            exit(1);
    }
}
