#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    map<char,int>mpp;
    for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
    }

    for(auto c:mpp){
        cout<<c.first<<"->"<<c.second<<endl;
    }
    
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<mpp[c]<<endl;;
    }
}