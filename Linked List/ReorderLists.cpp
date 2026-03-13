#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr){}
    ListNode(int x) : val(x),next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        stack<ListNode*> st;
        ListNode* curr=slow->next;
        slow->next=nullptr;
        while(curr){
            st.push(curr);
            curr=curr->next;
        }
        curr=head;
        while(!st.empty()){
            ListNode* next=curr->next;
            ListNode* node=st.top();
            st.pop();

            curr->next=node;
            node->next=next;
            curr=next;
        }
    }
};