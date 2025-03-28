#include <iostream>
#include <cmath>
using namespace std;

int sumofseries(int n) {
    if (n == 0) {
        return 0;
    }
    return (n * n * n) + sumofseries(n - 1);
}

int main() {
    int n;
    cin >> n;
    int result = sumofseries(n);
    cout << result << endl;

    return 0;
}