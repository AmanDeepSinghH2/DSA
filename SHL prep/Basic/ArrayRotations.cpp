#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Method 1: Juggling Algorithm for Left Rotation
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void leftRotate(vector<int>& arr, int d, int n) {
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        int temp = arr[i];
        int j = i;
        while (true) {
            int k = j + d;
            if (k >= n) k = k - n;
            if (k == i) break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

// Method 2: Reversal Algorithm for Right Rotation
void reverseArray(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rightRotate(vector<int>& arr, int d, int n) {
    d = d % n; 
    // Right rotate by d:
    // 1. Reverse whole array
    reverseArray(arr, 0, n - 1);
    // 2. Reverse first d elements
    reverseArray(arr, 0, d - 1);
    // 3. Reverse remaining elements
    reverseArray(arr, d, n - 1);
}

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    int n = arr1.size();
    
    cout << "Original Array: "; printArray(arr1);
    
    // Left Rotate by 2
    leftRotate(arr1, 2, n);
    cout << "Left Rotated by 2: "; printArray(arr1);

    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};
    // Right Rotate by 2
    rightRotate(arr2, 2, n);
    cout << "Right Rotated by 2: "; printArray(arr2);

    return 0;
}
