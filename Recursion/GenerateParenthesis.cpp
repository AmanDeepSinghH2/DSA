#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        GetParen(n,ans,"",0,0);
        return ans;
    }
    void GetParen(int n, vector<string>&ans, string s, int op,int cp){
        if(s.size()==n*2){
            ans.push_back(s);
            return;
        }
        if(op<n){
            GetParen(n,ans,s+"(",op+1,cp);
        }
        if(cp<op){
            GetParen(n,ans,s+")",op,cp+1);
        }
    }
};