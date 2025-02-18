#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data) {
    if(root == NULL) {
        root = createNode(data);
        return root;
    }
    if(data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversal(Node *root) {
    if(root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if(root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

Node *searchNode(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (root->data > data) {
        return searchNode(root->left, data);
    }
    return searchNode(root->right, data);
}

node* deleteNode(node* root, int data) {

    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
        
        }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main() {
    Node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Inorder traversal of the given tree is \n");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder traversal of the given tree is \n");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder traversal of the given tree is \n");
    postorderTraversal(root);
    printf("\n");

    int key = 40;
    Node *temp = searchNode(root, key);
    if (temp != NULL) {
        printf("Found %d in the tree\n", key);
    }
    else {
        printf("%d not found in the tree\n", key);
    }

    return 0;
}

