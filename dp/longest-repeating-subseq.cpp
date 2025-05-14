//https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

// for finding longest repeating subseq in a string we just have to pick same char but at diff indices.

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int lcs(string &s , string &q){
        int n=s.size();
        int m=q.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i-1]==q[j-1] && i!=j){
                    dp[i][j]= 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
    }
    int LongestRepeatingSubsequence(string &s) {
      
       return lcs(s,s);
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
