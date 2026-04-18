#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int count=0;
        for(int i=0;i<rows;i++){
            int left=0,right=cols-1;
            int fni=cols;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(matrix[i][mid]<0){
                    fni=mid;
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            count+=(cols-fni);        
        }
        return count;
    }
};