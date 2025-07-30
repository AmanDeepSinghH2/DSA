#include <bits/stdc++.h>
using namespace std;

int subarraysum(vector<int>&nums,int k){
    int n=nums.size();
    map<int,int> mpp;
    int prefixsum=0,cnt=0;
    mpp[0]=1;
    for(int i=n;i<n;i++){
        prefixsum+=nums[i];
        int rem=prefixsum-k;
        cnt+=mpp[rem];
        mpp[prefixsum]+=1;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = subarraysum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}