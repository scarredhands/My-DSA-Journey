//https://leetcode.com/problems/edit-distance/
//imp

class Solution {

public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        //dp[i][j]= min ways we can make first str of length i from word1 equal to first str of len j from word2;
       vector<vector<int>> dp(m+1,vector<int>(n+1));
       for(int i=0;i<=m;++i){
        dp[i][0]=i; //delete i ele of the 1st str
       }
       for(int j=0;j<=n;++j){
        dp[0][j]=j ;//add j ele in the 1st str
       }
       for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                //perform all 3 operations
                dp[i][j]=min(dp[i][j-1]+1, min(dp[i-1][j]+1,dp[i-1][j-1]+1));
            }
        }
       }
       return dp[m][n];
    }
};
