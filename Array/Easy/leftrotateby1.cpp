#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int n){
    int temp=nums[0];
    for(int i=0;i<n-1;i++){
        nums[i]=nums[i+1];
    }
    nums[n-1]=temp;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<endl;
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    rotate(nums, n);
    return 0;
}