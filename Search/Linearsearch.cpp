#include <bits/stdc++.h>
using namespace std;

void linearsearch(vector<int> &arr, int key) {
    for (int i = 0; i < arr.size(); i++) { // Fix: Check all elements
        if (arr[i] == key) {
            cout << key << " found at " << i << endl;
            return; // Exit after finding the key
        }
    }
    cout << key << " not found" << endl; // Handle case where key is not found
}

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) { // Fix: Use i < n
        int value;
        cin >> value;
        arr.push_back(value); // Dynamically add elements to the vector
    }
    int key;
    cin >> key;
    linearsearch(arr, key);
    return 0;
}