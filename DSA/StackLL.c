#include <stdio.h>
#include <stdlib.h>

// Define the structure for linked list node
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node *createNode(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(node **root, int data) {
    node *newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    newNode->next = *root;
    *root = newNode;
}

// Function to pop an element from the stack
int pop(node **root) {
    if (*root == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = (*root)->data;
    node *temp = *root;
    *root = (*root)->next;
    free(temp);
    return data;
}

// Function to print the stack
void printStack(node *root) {
    while (root != NULL) {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}

// Main function
int main() {
    node *root = NULL;
    push(&root, 1);
    push(&root, 2);
    push(&root, 3);
    printStack(root);
    printf("%d\n", pop(&root));
    printStack(root);
    return 0;
}
