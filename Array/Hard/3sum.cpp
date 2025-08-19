#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ThreeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum > 0) {
                k--;
            } else if (sum < 0) {
                j++;
            } else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                
                while (j < k && nums[j] == nums[j - 1]) j++;
                
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = ThreeSum(arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}