//https://neetcode.io/problems/longest-consecutive-sequence?list=blind75
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        map<int,int> mpp;
        for(auto it:nums){
            mpp[it]=1;
        }
        for(int i=0;i<nums.size();++i){
            int len=0;
           if(!mpp.count(nums[i]-1)){
            len=1;
            while(mpp.count(nums[i]+len)){
                len++;
            }
            ans=max(ans,len);
           }
        }
        return ans;
    }
};
