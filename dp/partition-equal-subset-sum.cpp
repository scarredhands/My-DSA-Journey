//https://leetcode.com/problems/partition-equal-subset-sum/
//tc= O(N*sum)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2) return false;
        
        //dp[i][j] = array of size i having partial sum j is possible or not
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
        for(int i=0;i<=n;++i){
            for(int j=0;j<=sum;++j){
                if(i==0 || j==0){
                    dp[i][j]=false;
                }
            }
        }
        dp[0][0]=true;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=sum;++j){
                if(nums[i-1]<=j){
                    dp[i][j]= (dp[i-1][j-nums[i-1]]) || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        return dp[n][sum/2];


    }
};
