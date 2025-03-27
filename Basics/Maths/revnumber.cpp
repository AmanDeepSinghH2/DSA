#include <bits-stdc++.h>
using namespace std;

int reverse(int n) {
    long long rev = 0;
    int sign = (n < 0) ? -1 : 1;
    n = abs((long long)n);
    while (n > 0) {
        int ld = n % 10;
        rev = rev * 10 + ld;
        if (rev > INT_MAX) return 0; // Check for overflow
        n /= 10;
    }
    return sign * rev;
}

int main(){
    int n;
    cin>>n;
    int reversedNumber = reverse(n);
    cout <<reversedNumber << endl;
}