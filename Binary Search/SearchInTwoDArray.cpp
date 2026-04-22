#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int low = 0;
    int high = row - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (target >= matrix[mid][0] && target <= matrix[mid][col - 1]) {
        return searchInRow(matrix, target, mid);
      } else if (target > matrix[mid][col - 1]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return false;
  }

  bool searchInRow(vector<vector<int>> &matrix, int target, int row) {
    int r = matrix.size();
    int c = matrix[0].size();
    int low = 0;
    int high = c - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (target == matrix[row][mid]) {
        return true;
      } else if (target > matrix[row][mid]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return false;
  }
};