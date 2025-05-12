//https://leetcode.com/problems/target-sum/
// the concept is to take out neg from all the nos. and do (sum of subset1)-(sum of subset2) = target and subset1+subset2= whole array.

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;++i){
            for(int j=0;j<=sum;++j){
                if(nums[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]= dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
            }
        }
        vector<int> arr;
        for(int j=0;j<(sum/2+1);++j){
            if(abs(sum-2*j)==abs(target)){
                arr.push_back(j);
            }
        }
        int ans=0;
        for(auto it:arr){
            ans+=(min(dp[n][it],dp[n][sum-it]));
        }
        return ans;
    }
};
