#include <bits/stdc++.h>
using namespace std;
int i=1;
void func(int n){
    cout<<"raj"<<" ";
    i++;
    if(i<=n){
    func(n);
    }
}

int main(){
    int n;
    cin>>n;
    func(n);
    return 0;
}