#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
    TreeNode* findmin(TreeNode* root){
        if(root == nullptr) return root;
        
        TreeNode* curr=root;
        while(curr->left){
            curr=curr->left;
        }
        return curr;
    }

    TreeNode* findmax(TreeNode* root){
        if(root == nullptr) return root;

        TreeNode* curr=root;
        while(curr->right){
            curr=curr->right;
        }
        return curr;
    }
};