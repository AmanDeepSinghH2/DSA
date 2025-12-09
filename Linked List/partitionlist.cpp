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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0), right(0);
        ListNode* L=&left;
        ListNode* R=&right;

        while(head){
            if(head->val<x){
                L->next=head;
                L=L->next;
            }
            else{
                R->next=head;
                R=R->next;
            }
            head=head->next;
        }
        R->next=nullptr;
        L->next=right.next;
        return left.next;
    }
};