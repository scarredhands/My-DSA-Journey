//https://leetcode.com/problems/palindrome-partitioning-ii/
//tc=O(N^2)

//example of front partition, not same as mcm
//solve it again
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0); // dp[i] = min cuts needed for substring [i..n-1]
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Precompute palindromes
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        // Bottom-up DP
        for (int i = n - 1; i >= 0; --i) {
            int mini = INT_MAX;
            for (int j = i; j < n; ++j) {
                if (isPal[i][j]) {
                    mini = min(mini, 1 + dp[j + 1]);
                }
            }
            dp[i] = mini;
        }

        return dp[0] - 1; // Because the last partition doesn't need a cut
    }
};
