#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n=nums.size();
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    for(auto it:mpp){
        if(it.second>(n/2)){
            return it.first;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}