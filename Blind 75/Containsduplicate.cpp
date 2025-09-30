#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> nums){
    int n= nums.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    bool x=0;
    for(auto it:mpp){
        if (it.second>1){
            x=1;
        }
    }
    return x;
}