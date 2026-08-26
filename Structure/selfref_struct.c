/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {

    struct Node *first = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    return 0;
} */


#include <stdio.h>
typedef struct str {
    int mem1;
    int mem2;
    struct str* next;
}str;
int main()
{
    str var1 = { 1, 2, NULL };
    str var2 = { 10, 20, NULL };
    var1.next = &var2;
    str *ptr1 = &var1;  
    printf("var2.mem1: %d\nvar2.mem2: %d", ptr1->next->
    mem1, ptr1->mem2);
    return 0;
}
                     
/*
str
┌─────────────┐
│ mem1        │ → integer
├─────────────┤
│ mem2        │ → integer
├─────────────┤
│ next        │ → address of another str
└─────────────┘

var1.next = &var2;
This is the most important line.

Suppose, just for visualization:

    var1 is at address 1000
    var2 is at address 2000

Then:
&var2

gives:
2000

So:
var1.next = &var2;

means:
Store the address of var2 inside var1.next.

Now:
var1                         var2


┌─────────────┐              ┌─────────────┐
│ mem1 = 1    │              │ mem1 = 10   │
│ mem2 = 2    │              │ mem2 = 20   │
│ next ───────┼─────────────→│ next = NULL │
└─────────────┘              └─────────────┘

This is essentially a tiny linked list:
var1 → var2 → NULL



Now this line
str *ptr1 = &var1;
We're creating a pointer called ptr1.

&var1 means:
Address of var1.

So:
ptr1
  │
  ↓
var1
┌─────────────┐
│ mem1 = 1    │
│ mem2 = 2    │
│ next ───────┼────→ var2
└─────────────┘

Therefore:
ptr1 → var1 → var2 → NULL

This is an important pointer chain.
*/