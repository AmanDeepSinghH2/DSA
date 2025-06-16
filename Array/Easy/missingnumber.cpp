#include <bits/stdc++.h>
using namespace std;

int missingnumber(vector<int> & nums){
	int n = nums.size();
	int total = n * (n + 1) / 2;
	int sum = 0;
	for (int num : nums) {
		sum += num;
	}
	return total - sum;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << missingnumber(nums) << endl;
    return 0;
}