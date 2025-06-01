#include <bits/stdc++.h>
using namespace std;

bool sorted(vector<int> &arr,int n){
    for(int i=0;i<=n;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            return false;
        }
        else{
            return true;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    return sorted(arr,n);
}