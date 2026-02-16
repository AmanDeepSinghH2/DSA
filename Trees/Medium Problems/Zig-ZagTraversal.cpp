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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> nq;
        nq.push(root);
        bool flag=true;
        while(!nq.empty()){
            int size=nq.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node=nq.front();
                nq.pop();
                int index=(flag)?i:(size-1-i);
                row[index]=node->val;
                if(node->left) nq.push(node->left);
                if(node->right) nq.push(node->right);
            }
            flag = !flag;
            result.push_back(row);
        }
        return result;
    }
};