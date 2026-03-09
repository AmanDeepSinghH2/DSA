#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool rotateString(string s, string goal){
        if(s.size()!=goal.size()) return false;
        string ds=s+s;
        return ds.find(goal)!=string::npos;
    }
};