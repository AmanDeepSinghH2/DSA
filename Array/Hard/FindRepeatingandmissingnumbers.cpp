#include <bits/stdc++.h>
using namespace std;

vector<int> findRM(vector<int> nums){
    int n = nums.size();
    vector<int> ans;
    map<int,int> mpp;
    for(auto it : nums){
        mpp[it]++;
    }
    for(auto it:mpp){
        if(it.second==2){
            ans.push_back(it.first);
        }
        for(int i = 1; i <= n; i++){
            if(mpp.find(i) == mpp.end()){
                ans.push_back(i);
                break;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2, 3};
    vector<int> result = findRM(nums);
    cout << "Repeating: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}