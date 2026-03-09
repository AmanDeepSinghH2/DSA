#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto p:mpp){
            pq.push({p.second,p.first});
        }
        string result="";
        while(!pq.empty()){
            auto[count,ch]=pq.top();
            pq.pop();
            result.append(count,ch);
        }
        return result;
    }
};