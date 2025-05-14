//https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    int lcs(string &s, string &q){
        int n=s.size();
        int m=q.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i-1]==q[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
    }
    int longestPalinSubseq(string &s) {
        string q=s;
        reverse(s.begin(),s.end());
        return lcs(s,q);
        
    }
};



int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}
