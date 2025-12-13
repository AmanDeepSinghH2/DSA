#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr){}
    ListNode(int x) : val(x),next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ans;
    ListNode* curr = head;
    
    while (curr) {
        ListNode* nextNode = curr->next;
        int nextGreater = 0;
        
        while (nextNode) {
            if (nextNode->val > curr->val) {
                nextGreater = nextNode->val;
                break;
            }
            nextNode = nextNode->next;
        }
        
        ans.push_back(nextGreater);
        curr = curr->next;
    }
    
    return ans;
}