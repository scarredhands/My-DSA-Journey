//https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1));
        for(int i=0;i<n;++i){
            dp[i][0]=0;

        }
        //max coins it can take is amount no. of 1 rupee coins.
        for(int j=1;j<=amount;++j){
            dp[0][j]=amount+1;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=amount;++j){
                if(coins[i-1]<=j){
                   
                    dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                   
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount]!=amount+1 ? dp[n][amount]: -1;
    }
};
