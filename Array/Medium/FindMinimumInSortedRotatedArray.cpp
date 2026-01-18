#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};

int main(){
    return 0;
}