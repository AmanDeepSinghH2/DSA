#include <stdio.h>
#include <stdlib.h>

typedef struct t {
    int data;
    struct t *left,*right;
}t;

t *root = NULL;

t* createNode(int data) {
    t *temp = (t *)malloc(sizeof(t));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

t* insertNode(t *root, int data) {
    if(root == NULL) {
        root = createNode(data);
    } else if(data <= root->data)
        root->left = insertNode(root->left,data);
    else
        root->right = insertNode(root->right,data);
    return root;
}

void inorder(t *root) {
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(t *root) {
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(t *root) {
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main() {
    root = insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}


