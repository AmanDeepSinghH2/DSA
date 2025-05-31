#include <bits/stdc++.h>
using namespace std;

int cdigits(int n) {
    if (n == 0) return 1;
    return log10(abs(n)) + 1;
}

int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "The number of digits in " << number << " is " << cdigits(number) << endl;
    return 0;
}