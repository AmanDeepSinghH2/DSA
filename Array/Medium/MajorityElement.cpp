#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n=nums.size();
    map<int,int>hash;
    for(int i=0;i<n;i++){
        hash[nums[i]]++;
    }
    for(auto it:hash){
        if(it.second>(n/2)){
            return it.first;
        }
    }
    return -1;        
}
int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = majorityElement(nums);
    if (result != -1) {
        cout << "Majority element is: " << result << endl;
    } else {
        cout << "No majority element found." << endl;
    }
    return 0;
}