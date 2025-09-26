#include <bits/stdc++.h>
using namespace std;

int triangleNumber(vector<int>& nums){
    int n=nums.size();
    int count=0;
    int Ts=0;
    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            Ts=nums[i]+nums[j];
            int k= lower_bound(nums.begin()+j+1,nums.end(),Ts)-nums.begin();
            count+=k-1-j;
        }
    }
    return count;
}