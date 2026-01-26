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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* Current=head;
        ListNode* next = NULL;
        while(Current!=NULL){
            next=Current->next;
            Current->next=prev;
            prev=Current;
            Current=next;
        }
        return prev;
    }
};