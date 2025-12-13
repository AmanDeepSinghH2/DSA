/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    ListNode* newHead = nullptr;
    ListNode* tail = nullptr;
    int maxVal = INT_MIN;
    curr = prev;
    while (curr) {
        if (curr->val >= maxVal) {
            maxVal = curr->val;
            if (!newHead) {
                newHead = curr;
                tail = curr;
            } else {
                tail->next = curr;
                tail = curr;
            }
        }
        curr = curr->next;
    }
    tail->next = nullptr;
    prev = nullptr;
    curr = newHead;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
};