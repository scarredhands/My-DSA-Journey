//https://leetcode.com/problems/trapping-rain-water/
//tc= O(N)
//sc=O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int leftMax=0;
        int rightMax=0;
        int n=height.size();
        int l=0;
        int r=n-1;
        while(l<r){
            //if left height is smaller => water level bound by leftMax-currHeight otherwise vice-versa
            if(height[l]<height[r]){
                if(height[l]>=leftMax){
                    leftMax=height[l];
                }
                else{
                    ans+=(leftMax-height[l]);
                }
                l++;
            }
            else{
                if(height[r]>=rightMax){
                    rightMax=height[r];
                }
                else{
                    ans+=(rightMax-height[r]);
                }
                r--;
            }
        }
        return ans;
        
    }
};
