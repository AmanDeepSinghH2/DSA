#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* Dummy = root;
        while(root){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return Dummy;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        TreeNode* RC=root->right;
        TreeNode* LR=FLR(root->left);
        LR->right=RC;
        return root->left;

    }
    TreeNode* FLR(TreeNode* root){
        if(root->right==NULL){
            return root;
        }
        return FLR(root->right);
    }
};