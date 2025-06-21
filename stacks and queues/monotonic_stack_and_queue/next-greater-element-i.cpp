//https://leetcode.com/problems/next-greater-element-i/

//tc=O(2N) = O(N)
//sc= O(2N)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mpp;
        stack<int> st;
        vector<int> ans;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                mpp[nums2[i]]=-1;
                st.push(nums2[i]);
            }
           else{
             while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                mpp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
            else{
                mpp[nums2[i]]=-1;
                st.push(nums2[i]);
            }
           }
        }

        for(auto it:nums1){
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};
