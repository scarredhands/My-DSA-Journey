//https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n,m;
        n=s1.size();
        m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int res=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    res=max(res,dp[i][j]);
                }
                else{
                  dp[i][j]=0;
                }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
