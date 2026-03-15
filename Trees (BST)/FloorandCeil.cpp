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
    int findceil(TreeNode* root,int key){
        int ceil=-1;
        while(root){
            if(root->val==key){
                ceil=root->data;
                return ceil;
            }
            if(key>root->val){
                root=root->right;
            }
            else{
                ceil=root->val;
                root=root->left;
            }
        }
        return ceil;
    };

    int findfloor(TreeNode* root, int key){
        int floor=1;
        
        while(root){
            if(root->val==key){
                floor=root->val;
                return floor;
            }
            if(key<root->val){
                root=root->left;
            }
            else{
                floor=root->val;
                root=root->right;
            }
        }
        return floor;
    }
};