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

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=nullptr;
        for(int key:preorder){
            root=insert(root,key);
        }
        return root;
    }
    TreeNode* insert(TreeNode* root, int &key){
        if(root==nullptr) return new TreeNode(key);
        if(key<root->val){
            root->left=insert(root->left,key);
        }
        else if(key>root->val){
            root->right=insert(root->right,key);
        }
        return root;
    }
};