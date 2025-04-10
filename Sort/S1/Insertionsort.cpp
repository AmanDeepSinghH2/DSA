#include <bits/stdc++.h>
using namespace std;

void insertionsort(int arr[],int n){
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j > 0 && arr[j] < arr[j-1]){
            int temp;
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionsort(arr, n);
    return 0;
}