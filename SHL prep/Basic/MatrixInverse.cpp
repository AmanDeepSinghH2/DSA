#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 3;

// Function to find determinant of a 3x3 matrix
int determinant(const vector<vector<int>>& mat) {
    int det = 0;
    // For 3x3 matrix:
    // det = a(ei - fh) - b(di - fg) + c(dh - eg)
    det = mat[0][0] * ((mat[1][1] * mat[2][2]) - (mat[2][1] * mat[1][2])) -
          mat[0][1] * ((mat[1][0] * mat[2][2]) - (mat[2][0] * mat[1][2])) +
          mat[0][2] * ((mat[1][0] * mat[2][1]) - (mat[2][0] * mat[1][1]));
    return det;
}

// Inverting a matrix is complex in C++ without libraries for general N.
// Here we just demonstrate determinant calculation which is a prerequisite for Inversion
// and condition for invertibility (det != 0).

int main() {
    vector<vector<int>> mat = { {6, 1, 1}, {4, -2, 5}, {2, 8, 7} };

    cout << "Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    int det = determinant(mat);
    cout << "Determinant: " << det << endl;

    if (det != 0)
        cout << "Matrix is Invertible." << endl;
    else
        cout << "Matrix is NOT Invertible." << endl;

    return 0;
}
