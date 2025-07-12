//https://leetcode.com/problems/shortest-common-supersequence/
//we cant space optimise lcs func here as we also have to print the string

class Solution {
private:
string longestCommonSubsequence(string s1, string s2){
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Reconstruct the LCS string
    string ans = "";
    int i = m, j = n;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            --i;
            --j;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            --i;
        else
            --j;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs=longestCommonSubsequence(str1,str2);
        int m=str1.size();
        int n=str2.size();
        int size=lcs.size();
        string ans="";
        int i,j,k;
        i=0;
        k=0;
        j=0;
        while(i<m && j<n && k<size){
            if(str1[i]==str2[j] && str1[i]==lcs[k]){
                ans+=lcs[k];
                k++;
                i++;
                j++;
            }
            else if(str1[i]==lcs[k] ){
                ans+=str2[j];
                j++;
            }
            else if(str2[j]==lcs[k]){
                ans+=str1[i];
                i++;
            }
            else{
                ans+=str2[j];
                j++;
                ans+=str1[i];
                i++;
            }
        }
        while(i<m){
            ans+=str1[i];
            i++;
        } 
        while(j<n){
            ans+=str2[j];
            j++;
        } 
        return ans;

    }
};
