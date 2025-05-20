//https://leetcode.com/problems/max-consecutive-ones-iii/

//if the condition for the sliding window is not satisfied then first make an if statement to satify that then write other conditions. 
// r will always move forward (in most of these type of problems)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;int r=0;
        int n=nums.size();
        int ans=0;
        int z=0;
        while(l<n && r<n){
            if(nums[r]==0){
                z++;
            }
            if(z>k){
                if(nums[l]==0){
                    z--;
                }
                l++;
            }
            r++;
            ans=max(ans,r-l);

        }
        return ans;
    }
};