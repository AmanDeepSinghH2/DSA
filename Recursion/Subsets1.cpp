#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        findSum(0,nums,ans,ds);
        return ans;
    }
    void findSum(int index, vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        ans.push_back(ds);
        for(int i=index;i<arr.size();i++){
            ds.push_back(arr[i]);
            findSum(i+1,arr,ans,ds);
            ds.pop_back();
        }
    }
};