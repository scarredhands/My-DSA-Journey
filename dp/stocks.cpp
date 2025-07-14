//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

//still cant understand the backward looping in the stocks problem.

class Solution {

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0)); this was not space optimised.
        vector<int>next(2,0);
        vector<int> curr(2,0);
        for(int i=n-1;i>=0;--i){
            //buy
            curr[1]= max(-prices[i]-fee+next[0], next[1]);
            //sell
            curr[0]=max(prices[i]+next[1],next[0]);
            next=curr;
        }
        return next[1];
    }
};
