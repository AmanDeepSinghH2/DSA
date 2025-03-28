#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n<=1){
        return n;
    }
    int x=fib(n-1);
    int y=fib(n-2);
    return x+y;
}
int main(){
    int n;
    cin>>n;
    int f=fib(n);
    cout<<f;
    return 0;

}