#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result="";
        string word="";
        vector<string> words;
        int n=s.size();
        for(int i=0; i<=n-1; i++){
            if(s[i]!=' '){
                word+=s[i];
            }
            else if(!word.empty()){
                words.push_back(word);
                word="";
            }
        }
        if(!word.empty()){
            words.push_back(word);
        }
        reverse(words.begin(),words.end());
        for(int i=0;i<=words.size()-1;i++){
            result+=words[i];
            if(i<words.size()-1){
                result+=' ';
            }
        }
        return result;
    }
};