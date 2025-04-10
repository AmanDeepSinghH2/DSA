#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    int left = low, right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high) {
        if (arr[left] < arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergesort(vector<int> &arr, int low, int high) {
    if (low >= high) { // Base case to stop recursion
        return;
    }
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);     // Recursively sort left half
    mergesort(arr, mid + 1, high); // Recursively sort right half
    merge(arr, low, mid, high);  // Merge both halves
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    mergesort(arr, 0, arr.size() - 1);

    // Printing sorted array
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}