#include <bits/stdc++.h>
using namespace std;

int largest(const vector<int> &arr){
    int maxVal = arr[0];
    for(size_t i = 1; i < arr.size(); i++){
        if(arr[i] > maxVal){
            maxVal = arr[i];
        }
    }
    return maxVal; 
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int l = largest(arr);
    cout << l << endl;
    return 0;
}