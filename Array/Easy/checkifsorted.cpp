#include <bits/stdc++.h>
using namespace std;

bool sorted(const vector<int> &arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    if (sorted(arr, n)) {
        cout << "Sorted" << endl;
    } else {
        cout << "Not sorted" << endl;
    }
    return 0;
}