#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node==NULL || node->next==NULL){
            return;
        }
        ListNode* nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        delete nextNode;
    }
};