#include <iostream>
using namespace std;

int main() {
    int n, j, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) { // Fix: Changed condition to i < n
        cin >> arr[i];
    }
    for (j = n - 1; j >= 0; j--) { // Fix: Changed condition to j >= 0
        cout << arr[j] << " "; // Added space for better output formatting
    }
    return 0;
}