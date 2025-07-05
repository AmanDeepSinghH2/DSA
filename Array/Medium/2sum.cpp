#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> num_with_index;
    for (int i = 0; i < nums.size(); ++i) {
        num_with_index.push_back({nums[i], i});
    }
    sort(num_with_index.begin(), num_with_index.end());

    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = num_with_index[left].first + num_with_index[right].first;
        if (sum == target) {
            return {num_with_index[left].second, num_with_index[right].second};
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    return {};
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }
    return 0;
}