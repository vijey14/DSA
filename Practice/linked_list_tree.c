
#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a binary tree
struct node* create()
{
    struct node *temp;
    int data, choice;

    printf("\nPress 1 to create a new node");
    printf("\nPress 0 to exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // If choice is 0, no node is created
    if (choice == 0)
    {
        return NULL;
    }

    // Allocate memory for new node
    temp = (struct node*)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory allocation failed!");
        return NULL;
    }

    // Get data for the node
    printf("Enter the data: ");
    scanf("%d", &data);

    temp->data = data;

    // Create left child
    printf("\nEnter the left child of %d:", data);
    temp->left = create();

    // Create right child
    printf("\nEnter the right child of %d:", data);
    temp->right = create();

    return temp;
}

// Inorder traversal to display the tree
void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct node *root;

    root = create();

    printf("\nInorder Traversal: ");
    inorder(root);

    return 0;
}
