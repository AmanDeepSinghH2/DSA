#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* newhead = reverse(slow);

        // Compare halves
        ListNode* first = head;
        ListNode* second = newhead;
        bool result = true;
        while(second != NULL) {
            if(first->val != second->val) {
                result = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        // Restore list
        reverse(newhead);

        return result;
    }
};
