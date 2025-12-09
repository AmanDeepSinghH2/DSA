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
    ListNode* swapPairs(ListNode* head) {
        ListNode DUM(0);
        DUM.next=head;
        ListNode* prev=&DUM;
        while(head && head->next){
            ListNode* first=head;
            ListNode* second=head->next;

            prev->next=second;
            first->next=second->next;
            second->next=first;

            prev=first;
            head=first->next;
        }
        return DUM.next;
    }
};