#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k){
        int n = nums.size();
        if (n == 1) return;  // Fix: No need to rotate a single-element array

        k = k % n;  // Ensure k does not exceed array size

        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    rotate(nums, k);
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}