//https://leetcode.com/problems/maximum-subarray/

//kadane algo is basically at each i u have a choice of starting a new arr from i or continue with the existing array based on the sum of both choices.
//and keeping track of the global maxima of the sub arr at each point . this will be your ans.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int maxEndingHere=nums[0];
        for(int i=1;i<nums.size();++i){
            maxEndingHere=max(maxEndingHere+nums[i],nums[i]);
            ans=max(ans,maxEndingHere);

        }
        return ans;
    }
};