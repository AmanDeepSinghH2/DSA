#include <bits-stdc++.h>
using namespace std;

int gcdf(int x,int y){
    int gcd=1;
    for(int i=1;i<=min(x,y);i++){
        if(x%i==0 and y%i==0){
            gcd=i;
        }
    }
    return gcd;
}

int main(){
int n,o;
cin>>n>>o;
cout<<gcdf(n,o)<<endl;
return 0;
}