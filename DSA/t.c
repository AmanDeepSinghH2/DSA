#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}T;

T*creatnode(T*root,int data){
    T*newnode=(int*)malloc(sizeof(int));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
T*insert(T*root,int data){
    if(root==NULL){
        root=createnode(root,data);
        return root;
    }
    if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else if(data>=root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

T*search(T*root,int data){
    if(data==root->data){
        return root;
    }
    if(data<=root->data){
        root->left=search(root->left,data);
    }
    else if(data>=root->right){
        root->right=search(root->right,data);
    }
    return root;
}

T*delete(T*root, data){
    if(root==NULL){
        return root;
    }
    if(data<=root->data){
        root->left=delete(root->left,data);
    }
    else if(data>=root->data){
        root->right=delete(root->right,data);
    }
    if{
        if(root->left==NULL){
            T*temp=root->right;
            free(temp);
            return temp;
        }
        else{
            T*temp=root->left;
            free(temp);
            return temp;
        }
    }
}
