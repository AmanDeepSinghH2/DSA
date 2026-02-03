#include <iostream>
#include <vector>

using namespace std;

const int N = 3; // Matrix Size 3x3

void addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
}

int getTrace(const vector<vector<int>>& A) {
    int trace = 0;
    for (int i = 0; i < N; i++)
        trace += A[i][i];
    return trace;
}

void printMatrix(const vector<vector<int>>& mat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    vector<vector<int>> B = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    vector<vector<int>> C(N, vector<int>(N));

    cout << "Matrix A:" << endl; printMatrix(A);
    cout << "Matrix B:" << endl; printMatrix(B);

    addMatrices(A, B, C);
    cout << "Sum (A + B):" << endl; printMatrix(C);

    cout << "Trace of A: " << getTrace(A) << endl;

    return 0;
}
