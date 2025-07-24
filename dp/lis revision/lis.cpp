//https://leetcode.com/problems/longest-increasing-subsequence/
//tc= O(N);

//pls revise

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;++i){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                cnt++;
            }
            else{
                auto ind=lower_bound(temp.begin(),temp.end(),nums[i]);
                *ind=nums[i];
            }
        }
        return cnt;
    }
};
# include <bits/std.c++