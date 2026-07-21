#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findperm(0,nums,ans);
        return ans;
    }
    void findperm(int ind,vector<int>&nums,vector<vector<int>>&ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            findperm(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
};
