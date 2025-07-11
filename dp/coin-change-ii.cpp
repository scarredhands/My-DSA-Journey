//https://leetcode.com/problems/coin-change-ii/

//trying space optimised dp for the first time ;)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
      // use unsigned int to escape runtime err
        vector<unsigned long long> dp1(amount+1,0); //prev row
        dp1[0]=1;
        for(int i=1;i<=n;++i){

            vector<unsigned long long> dp2(amount+1,0); //curr row
            dp2[0]=1;
            for(int j=1;j<=amount;++j){
                if(coins[i-1]<=j){
                    dp2[j]=dp2[j-coins[i-1]] + dp1[j];
                }
                else{
                    dp2[j]=dp1[j];
                }
            }
            dp1=dp2;
        }
        return dp1[amount];
    }
};
