#include <bits/stdc++.h>
using namespace std;

int singlenumber(vector <int>& nums){
    map<int,int> hash;
    int n=nums.size();
    for(int i=0;i<n;i++){
        hash[nums[i]]++;
    }
    for(auto j:hash){
        if (j.second == 1){
            return j.first;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = singlenumber(nums);
    cout << "Single number is: " << result << endl;
    return 0;
}