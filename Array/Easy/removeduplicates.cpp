#include <bits/stdc++.h>
using namespace std;

bool sorted(vector<int>& arr) {
    int count = 0, n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[(i + 1) % n]) count++;
        if (count > 1) return false;
    }
    return true;
}

int removeDuplicates(vector<int>& arr) {
    int k = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[k - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }
    return k;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5};
    int newSize = removeDuplicates(arr);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "Is the array sorted or rotated sorted? ";
    if (sorted(arr)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
