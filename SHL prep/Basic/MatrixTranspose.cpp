#include <iostream>
#include <vector>

using namespace std;

const int N = 3;

void transpose(vector<vector<int>>& A, vector<vector<int>>& B) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            B[i][j] = A[j][i];
}

void printMatrix(const vector<vector<int>>& mat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = { {1, 1, 1}, {2, 2, 2}, {3, 3, 3} };
    vector<vector<int>> B(N, vector<int>(N));

    cout << "Original Matrix:" << endl; printMatrix(A);

    transpose(A, B);

    cout << "Transposed Matrix:" << endl; printMatrix(B);

    return 0;
}
