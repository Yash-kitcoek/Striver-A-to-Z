// Leetcode 121
#include<iostream>
#include<vector>
using namespace std;

int buySell(vector<int> &prices) {
    int maxProfit = 0, bestBuy = prices[0];

    for(int i=0; i<prices.size(); i++) {
        if(prices[i] > bestBuy) {
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }

        bestBuy = min(bestBuy, prices[i]);
    }

    return maxProfit;
}


int buySell2(vector<int> &prices) {
    int profit = 0;

    for(int i=0; i < prices.size(); i++) {
        if(prices[i] > prices[i-1]) {
            profit += prices[i] - prices[i-1];
        }
    }
    return profit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    
    cout <<    buySell(prices);

    cout <<endl;

    cout <<    buySell2(prices);
}