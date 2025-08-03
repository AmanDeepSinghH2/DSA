#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> PascalT(int n){
    vector<vector<int>> ans;
    for(int row=1;row<=n;row++){
        ans.push_back(generaterow(row));
    }
    return ans;
}

vector<int> generaterow(int row){
    long long ans=1;
    vector<int> ansrow;
    ansrow.push_back(ans);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/col;
        ansrow.push_back(ans);
    }
    return ansrow;
}