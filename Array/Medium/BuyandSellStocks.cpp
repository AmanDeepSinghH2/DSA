#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
    int n=prices.size();
    int mini=prices[0];
    int profit=0;
    for(int i=0;i<n;i++){
        int cost=prices[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,prices[i]);
    }
    return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}