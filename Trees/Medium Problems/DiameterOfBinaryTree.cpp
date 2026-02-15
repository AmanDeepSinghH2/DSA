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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dm=0;
        height(root,dm);
        return dm;
    }
private:
    int height(TreeNode* root, int &dm){
        if(!root) return 0;
        int lh=height(root->left,dm);
        int rh=height(root->right,dm);
        dm=max(dm,lh+rh);
        return 1+max(lh,rh);
    }
};