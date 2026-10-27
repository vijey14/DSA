#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

/* Create a new node */
struct Node* new_node(int value) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

/* Insert a node */
void insert(struct Node *root, int value) {
    if (value < root->data) {
        if (root->left == NULL)
            root->left = new_node(value);
        else
            insert(root->left, value);
    } else {
        if (root->right == NULL)
            root->right = new_node(value);
        else
            insert(root->right, value);
    }
}

/* Search for an element */
struct Node* search(struct Node *root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

/* Inorder: Left, Root, Right */
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder: Root, Left, Right */
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder: Left, Right, Root */
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Find the smallest node in a subtree */
struct Node* findSmallestNode(struct Node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

/* Delete a node */
struct Node* delete(struct Node *root, int value) {
    struct Node *temp;

    if (root == NULL)
        return NULL;

    if (value < root->data) {
        root->left = delete(root->left, value);
    } else if (value > root->data) {
        root->right = delete(root->right, value);
    } else {
        /* Case 1 and Case 2: No child or one child */
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        /* Case 3: Two children */
        temp = findSmallestNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}

int main() {
    struct Node *root = new_node(20);
    struct Node *result;

    insert(root, 5);
    insert(root, 1);
    insert(root, 15);
    insert(root, 9);
    insert(root, 7);
    insert(root, 12);
    insert(root, 30);
    insert(root, 25);
    insert(root, 40);
    insert(root, 45);
    insert(root, 42);

    /* Display inorder traversal before deletion */
    inorder(root);
    printf("\n");

    /* Search for an element */
    result = search(root, 15);

    if (result != NULL)
        printf("Element found\n");
    else
        printf("Element not found\n");

    /* Delete the elements specified in the manual */
    root = delete(root, 1);
    root = delete(root, 40);
    root = delete(root, 45);
    root = delete(root, 9);

    /* Display inorder traversal after deletion */
    inorder(root);
    printf("\n");

    return 0;
}