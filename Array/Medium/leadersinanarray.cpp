#include<bits/stdc++.h>
using namespace std;

void leaderinanarray(vector<int>&arr){
    int n=arr.size();
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            temp.push_back(arr[i]);
        }
    }
    for(auto it:temp){
        cout<<it;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    leaderinanarray(arr);
    return 0;
}