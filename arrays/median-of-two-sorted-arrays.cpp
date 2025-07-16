//https://leetcode.com/problems/median-of-two-sorted-arrays/
//tc= O(log(m+n))

//main concept here is- left1+left2+right1+right2 must be the final array
// left1 is obv less than right1 so no need to check that, left1<right1 will be checked and vice versa for left2 and right1;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low=0;
        int high=m;
        while(low<=high){
            //we know i+j= (m+n+1)/2;
           int i=low+ (high-low)/2; //partition ind of nums1
            int j=(m+n+1)/2 -i;     //partition ind of nums2

            int maxLeft1= (i==0) ? INT_MIN: nums1[i-1];
            int maxLeft2= (j==0)? INT_MIN: nums2[j-1];
            int minRight1= (i==m)? INT_MAX : nums1[i];
            int minRight2= (j==n) ? INT_MAX : nums2[j];  

            if(maxLeft1<=minRight2 && maxLeft2<=minRight1){
                if((m+n)%2){
                    return max(maxLeft1,maxLeft2);
                }
                else{
                    return (max(maxLeft1,maxLeft2)+ min(minRight1,minRight2))/2.0;
                }
            }
            else{
                if(maxLeft1>minRight2){
                   high=i-1;
                }
                else{
                    low=i+1;
                }
            }      
            }
            return 0.0;

    }
};
