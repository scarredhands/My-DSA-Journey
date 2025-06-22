//https://leetcode.com/problems/largest-rectangle-in-histogram/
//great solution do revise. when u have to find both next smaller ele and prev smaller ele

//tc=O(2N) = O(N)
//sc=O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int> st;
        int n=heights.size();
        for(int i=0;i<n;++i){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int next=i;  //nse
                int curr=st.top();  //curr ele= height of rectangle
                st.pop();
                int prev= st.empty()? -1 :st.top();  //pse
                int area= heights[curr]*(next-prev-1);
                ans=max(ans,area);

            }
            st.push(i);
        }
        while(!st.empty()){
            int next=n;
            int curr=st.top();
            st.pop();
            int prev=st.empty()?-1:st.top();
            int area= heights[curr]*(next-prev-1);
             ans=max(ans,area);
        }

        return ans;

    }
};
