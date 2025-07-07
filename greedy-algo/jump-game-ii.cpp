//https://leetcode.com/problems/jump-game-ii/

//please revise this
//tc= O(n)

class Solution {
public:
    int jump(vector<int>& nums) {
        int moves=0;
        int n=nums.size();
        int mini=0;
        int maxi=0;
        if(n==1) return 0;
        while(mini<n-1 && maxi<n-1){
           int newMaxi=0;
            for(int i=mini;i<=maxi;++i){
               
                newMaxi=max(newMaxi,nums[i]+i);
            }
            mini=maxi+1;
            maxi=newMaxi;
            
            moves++;
        }
        return moves;
    }
};
