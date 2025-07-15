#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums){
    int n=nums.size();
    int posindex=0;
    int negindex=1;
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            ans[posindex]=nums[i];
            posindex+=2;
        }
        else{
            ans[negindex]=nums[i];
            negindex+=2;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> result = rearrangeArray(nums);

    cout << "Rearranged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}