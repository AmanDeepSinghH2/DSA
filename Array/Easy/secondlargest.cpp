#include <bits/stdc++.h>
using namespace std;

int secondlargest(const vector<int> &arr,int n){
    int largest = INT_MIN;
    int slargest = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        } else if(arr[i] > slargest && arr[i] != largest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int s = secondlargest(arr, n);
    cout << s;
    return 0;
}