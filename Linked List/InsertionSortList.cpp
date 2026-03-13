#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* curr = head;
        while(curr!=nullptr && curr->next!=nullptr){
            if(curr->val<=curr->next->val){
                curr=curr->next;
            }
            else{
                ListNode* toinsert=curr->next;
                curr->next=toinsert->next;

                ListNode* prev=&dummy;
                while(prev->next->val <= toinsert->val){
                    prev=prev->next;
                }
                toinsert->next=prev->next;
                prev->next=toinsert; 
            }
        }
        return dummy.next;
    }
};