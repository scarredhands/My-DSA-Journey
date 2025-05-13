//https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n,m;
        n=s1.size();
        m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
