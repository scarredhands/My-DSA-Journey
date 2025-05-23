//https://leetcode.com/problems/count-number-of-nice-subarrays/

//in these kinda problems where u have to get no. of subarrays, the original way to get subarrays is of approx O(N^2)... optimal sol can have worst TC as (4N)

// finding subarrays eq to a certain no. takes more time so instead we will find subarrays less than eq to that no. - final sol= f(k)-f(k-1) 

class Solution {
public:
   int lessThanK(vector<int> &nums, int k){
    int ans=0;
    int l=0;
    int r=0;
    int odd=0;
    while(l<nums.size() && r<nums.size()){
        if(nums[r]%2!=0){
            odd++;
        }
        while(odd>k){
            if(nums[l]%2!=0){
                odd--;
                
            }
            l++;
        }
        ans+=(r-l+1);
        r++;
    }
    return ans;
   }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return lessThanK(nums,k)-lessThanK(nums,k-1);
    }
};
