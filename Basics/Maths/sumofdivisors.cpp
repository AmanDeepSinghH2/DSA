#include <iostream>
using namespace std;

int sumOfDivisors(int n) {
    int totalSum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                totalSum += j;
            }
        }
    }
    return totalSum;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Sum of divisors from 1 to " << n << " is: " << sumOfDivisors(n) << endl;
    return 0;
}