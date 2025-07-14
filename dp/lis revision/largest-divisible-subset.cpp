//https://leetcode.com/problems/largest-divisible-subset/
//tc= O(n)
//sc= O(n)
//revise this

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // sort it first
        int n=nums.size();
        vector<int> dp(n,1) , parent(n,-1);
        
        int maxi=0;
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
             if(dp[i]>dp[maxi]) maxi=i;
        }
        vector<int> ans;
        for(int i=maxi;i>=0;i=parent[i]){
            ans.push_back(nums[i]);
        }
        return ans;

    }
};
