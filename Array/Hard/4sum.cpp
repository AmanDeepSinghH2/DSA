#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int k = j + 1;
            int d = n - 1;

            while (k < d) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[d];

                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k], nums[d]});
                    k++;
                    d--;

                    while (k < d && nums[k] == nums[k - 1]) k++;
                    while (k < d && nums[d] == nums[d + 1]) d--;
                } else if (sum < target) {
                    k++;
                } else {
                    d--;
                }
            }
        }
    }

    return ans;
}
