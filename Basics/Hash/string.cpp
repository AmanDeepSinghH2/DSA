#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Use a larger hash array to accommodate all ASCII characters
    int hash[256] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while (q--) {
        char character;
        cin >> character;
        cout << hash[character] << endl;
    }

    return 0;
}