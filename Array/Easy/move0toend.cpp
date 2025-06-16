#include <iostream>
#include <vector>
using namespace std;

void movezeros(vector<int> &nums){
    vector<int> temp;
    for(int i=0; i<nums.size(); i++){
        if (nums[i]!=0){
            temp.push_back(nums[i]);
        }
    }
    int n=temp.size();
    for(int i=0; i<temp.size(); i++){
        nums[i]=temp[i];
    }
    for(int i=n; i<nums.size(); i++){
        nums[i]=0;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    movezeros(nums);
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    cout << endl;
    return 0;
}