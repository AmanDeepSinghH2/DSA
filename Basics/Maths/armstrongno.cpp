#include <bits-stdc++.h>
using namespace std;

int armstrong(int n) {
    int sum=0;
    while(n>0){
        int x=n%10;
        n=n/10;
        sum=sum+(pow(x,3));
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    int aNumber = armstrong(n);
    cout <<aNumber << endl;
    return 0;
}