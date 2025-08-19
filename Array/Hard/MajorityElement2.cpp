#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n=nums.size();
    vector<int> ans;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }

    for(auto it:mpp){
        if(it.second>(n/3)){
            ans.push_back(it.first);
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1,1,2, 2};
    vector<int> res = majorityElement(nums);
    cout << "Majority Element(s): ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}