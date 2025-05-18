//https://leetcode.com/problems/triangle/

class Solution {
public:
  int minPath(vector<vector<int>> & triangle,int n,int j){
    if(n==triangle.size()){
        return 0;
    }
    int sum= triangle[n][j] +min(minPath(triangle,n+1,j), minPath(triangle,n+1,j+1));
    return sum;
  }
    int minimumTotal(vector<vector<int>>& triangle) {
       int n= triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;++j)
{
    dp[n-1][j]=triangle[n-1][j];
}        for(int i=n-2;i>=0;--i){
            for(int j=0;j<=i;++j){
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+ triangle[i][j];
            }
        }
     
        return dp[0][0];

    }
};
