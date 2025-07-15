//https://leetcode.com/problems/burst-balloons/
//tc= O(n^3)

class Solution {
private:
    int solve(vector<int>& nums, int i, int j,vector<vector<int>> &memo){
        if(j-i<=1)return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int maxi=INT_MIN;
        for(int k=i+1;k<j;++k){
            int temp= solve(nums,i,k,memo)+ solve(nums,k,j,memo) + nums[i]*nums[k]*nums[j];
            maxi=max(maxi,temp);
        }
        return memo[i][j]= maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(1);
        for(auto it:nums){
            arr.push_back(it);
        }
        arr.push_back(1);
        vector<vector<int>> memo(arr.size(),vector<int>(arr.size(),-1));
        return solve(arr,0,arr.size()-1,memo);
    }
};
