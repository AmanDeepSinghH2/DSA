int pairSum(ListNode* head) {
    vector<int> values;
    while (head) {
        values.push_back(head->val);
        head = head->next;
    }
    
    int maxSum = 0;
    int n = values.size();
    for (int i = 0; i < n/2; i++) {
        maxSum = max(maxSum, values[i] + values[n-1-i]);
    }
    
    return maxSum;
}