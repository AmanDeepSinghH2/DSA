#include <bits/stdc++.h>
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
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }

    vector<int> BoundaryTraversal(TreeNode* root){
        vector<int> ans;
        if(!root) return ans;
        if(!isLeaf(root))ans.push_back(root->val);
        addleft(root,ans);
        addLeaf(root,ans);
        addright(root,ans);
        return ans;
    }

    void addleft(TreeNode* root,vector<int>& ans){
        TreeNode* curr=root->left;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->val);
            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }
    }
    void addLeaf(TreeNode* root,vector<int>& ans){
        if(isLeaf(root)) {ans.push_back(root->val); return;}
        if(root->left) addLeaf(root->left,ans);
        if(root->right) addLeaf(root->right,ans);
    }

    void addright(TreeNode* root, vector<int>& ans){
        TreeNode* curr=root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->val);
            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
};

