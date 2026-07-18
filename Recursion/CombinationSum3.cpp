#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(n,1,k,ans,ds);
        return ans;
    }
    void findCombination(int sum, int last, int k, vector<vector<int>>&ans, vector<int>&ds){
        if(sum==0 && ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(sum<=0 || ds.size()>k) return;
        for(int i=last;i<=9;i++){
            if(i<=sum){
                ds.push_back(i);
                findCombination(sum-i,i+1,k,ans,ds);
                ds.pop_back();
            }
            else{break;}
        }
    }
};