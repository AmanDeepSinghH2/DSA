#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int mcount=0;
        for(int i=0; i<s.size();i++){
            if(s[i]=='(') count++;
            else if(s[i]==')') count--;
            mcount=max(mcount,count);
        }
        return mcount;
    }
};