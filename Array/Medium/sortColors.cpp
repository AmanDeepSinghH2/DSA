#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortColors(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (auto it : nums) {
        cout << it;
    }
    cout << endl;
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    return 0;
}
