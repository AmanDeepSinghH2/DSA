#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
} t;

t *root = NULL;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(t *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

t *newNode(int data) {
    t *Node = (t *)malloc(sizeof(t));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    Node->height = 1;
    return (Node);
}

t *rightRotate(t *y) {
    t *x = y->left;
    t *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

t *leftRotate(t *x) {
    t *y = x->right;
    t *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(t *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

t *insert(t *node, int data) {
    if (node == NULL)
        return (newNode(data));

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(t *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(t *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(t *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Preorder traversal of the"
            " constructed AVL tree is \n");
    preOrder(root);
    printf("\n");

    printf("Inorder traversal of the"
            " constructed AVL tree is \n");
    inOrder(root);
    printf("\n");

    printf("Postorder traversal of the"
            " constructed AVL tree is \n");
    postOrder(root);
    printf("\n");

    return 0;
}

