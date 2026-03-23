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

class NodeValue {
public:
    int minNode, maxNode, sum;
    bool isBST;
    NodeValue(int minNode, int maxNode, int sum, bool isBST) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
        this->isBST = isBST;
    }
};

class Solution {
private:
    int maxSum = 0;

    NodeValue maxSumBSTHelper(TreeNode* root) {
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0, true);

        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);

        if (left.isBST && right.isBST && left.maxNode < root->val && root->val < right.minNode) {
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);
            return NodeValue(min(root->val, left.minNode),
                             max(root->val, right.maxNode),
                             currSum,
                             true);
        }

        return NodeValue(INT_MIN, INT_MAX, 0, false);
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return maxSum;
    }
};