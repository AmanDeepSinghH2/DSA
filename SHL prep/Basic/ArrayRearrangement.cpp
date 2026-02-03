#include <iostream>
#include <vector>

using namespace std;

// Function to move all zeros to the end of the array
void pushZerosToEnd(vector<int>& arr) {
    int n = arr.size();
    int count = 0; // Count of non-zero elements

    // Traverse the array. If element encountered is non-zero, then
    // replace the element at index 'count' with this element
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            arr[count++] = arr[i];

    // Now all non-zero elements have been shifted to front and 'count' is
    // set as index of first 0. Make all elements 0 from count to end.
    while (count < n)
        arr[count++] = 0;
}

// Rearrange positive and negative numbers
// Move all negative numbers to beginning and positive to end
void rearrangePosNeg(vector<int>& arr) {
    int j = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    cout << "Original Array: "; printArray(arr);
    
    pushZerosToEnd(arr);
    cout << "Zeros moved to end: "; printArray(arr);

    vector<int> arr2 = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    cout << "\nOriginal Mixed Array: "; printArray(arr2);
    rearrangePosNeg(arr2);
    cout << "Rearranged (Negatives first): "; printArray(arr2);

    return 0;
}
