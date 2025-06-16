#include <bits/stdc++.h>
using namespace std;

int maximumconsequitiveones(vector<int> &nums){
    int count=0;
    int maxcount=0;
    int n=nums.size();
    for(int i=0;i<=n;i++){
        if(nums[i]==1){
            count++;
        }
        else {
            count=0;
        }
        maxcount=max(maxcount,count);
    }
    return maxcount;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1};
    cout << "Maximum consecutive ones: " << maximumconsequitiveones(nums) << endl;
    return 0;
}