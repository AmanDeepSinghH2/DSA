#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string st;
        int level=0;
        for(char ch : s){
            if(ch == '('){
                if(level>0){
                    st+='(';
                }
                level++;
            }
            else if(ch == ')' ){
                level--;
                if(level>0) st+=')';
            }
        }
        return st;
    }
};