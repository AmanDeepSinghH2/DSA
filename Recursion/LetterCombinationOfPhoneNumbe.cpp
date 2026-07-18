#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s="";
        findLC(digits,ans,s,0);
        return ans;
    }
    void findLC(string digits,vector<string>&ans,string s,int index=0){
        string combos[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }
        int digit=digits[index]-'0';
        for(int i=0;i<combos[digit].size();i++){
            findLC(digits,ans,s+combos[digit][i],index+1);
        }
    }
};