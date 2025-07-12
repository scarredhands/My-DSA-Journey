//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/1695479325/

class Solution {
private:
    int dp[100001][3][2]; // dp[day][transactions_left][holding]

    int solve(vector<int>& prices, int id, int transactions, int holding) {
        if (id == prices.size() || transactions == 0) return 0;
        if (dp[id][transactions][holding] != -1) return dp[id][transactions][holding];

        int ans = 0;
        if (holding) {
            // Option 1: Sell today
            ans = max(ans, prices[id] + solve(prices, id + 1, transactions - 1, 0));
            // Option 2: Hold the stock
            ans = max(ans, solve(prices, id + 1, transactions, 1));
        } else {
            // Option 1: Buy today
            ans = max(ans, -prices[id] + solve(prices, id + 1, transactions, 1));
            // Option 2: Skip
            ans = max(ans, solve(prices, id + 1, transactions, 0));
        }

        return dp[id][transactions][holding] = ans;
    }

public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 2, 0); // start at day 0, 2 transactions, not holding any stock
    }
};
