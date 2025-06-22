//https://leetcode.com/problems/maximal-rectangle/

//tc=O(M*N)
//sc=O(M*N)

class Solution {
private:
    int maxArea(vector<int> &arr){
        stack<int> st;
        int maxi=0;
        int n=arr.size();
        for(int i=0;i<n;++i){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int next=i;
                int curr=st.top();
                st.pop();
                int prev=st.empty()?-1 : st.top();
                int area= arr[curr]*(next-prev-1);
                maxi=max(maxi,area);
            }
            st.push(i);          
        }
        while(!st.empty()){
                int next=n;
                int curr=st.top();
                st.pop();
                int prev=st.empty()?-1 : st.top();
                int area= arr[curr]*(next-prev-1);
                maxi=max(maxi,area);
            }
            return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>> height(r,vector<int>(c));
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(i==0){
                    height[i][j]=matrix[i][j]-'0';
                }
                else{
                    height[i][j]=(matrix[i][j]-'0'==1)? height[i-1][j]+1: 0;
                }
            }
        }
        int maxi=0;
        for(int i=0;i<height.size();++i){
            int area= maxArea(height[i]);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
