Best Time to Buy and Sell Stock
=======

##Description
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

##Solution
```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minIndex = 0;
        int profit = 0;
        for(int i=0;i<prices.size();++i){
            if(prices[i]<prices[minIndex])
                minIndex = i;
            if(profit<prices[i] - prices[minIndex])
                profit = prices[i] - prices[minIndex];
        }
        return profit;
    }
};
```