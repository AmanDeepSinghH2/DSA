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
    ListNode* findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1){
            temp->next=l1;
        }
        else{
            temp->next=l2;
        }
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* middle=findmiddle(head);
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=nullptr;

        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        return merge(lefthead,righthead);
    }
};