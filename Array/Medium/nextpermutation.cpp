#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>&nums){
    int n=nums.size();
    int ind=-1;
    for(int i=n-2;i>=0;i--){
        if(nums[i]>nums[i+1]){
            ind=0;
            break;
        }
    }
    if (ind==-1){
        reverse(nums.begin(),nums.end());
        return;
    }
    for(int i=n-1;i>ind;i--){
        if(nums[i]>nums[ind]){
            swap(nums[i],nums[ind]);
            break;
        }
    }
    reverse(nums.begin()+ind+1,nums.end());
    for(int i=0;i<n;i++){
        cout<<nums[i];
    }
}
int main() {
    vector<int> nums = {1, 2, 3};
    cout << "Original: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    cout << "Next permutation: ";
    nextPermutation(nums);
    cout << endl;

    return 0;
}