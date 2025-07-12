//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

//tc=O(m*n)
//sc= O(n) where n is size of str

class Solution {
private:
     int longestCommonSubsequence(string text1, string text2) {
         int m = text1.size();
        int n = text2.size();
        
        vector<int> prev(n+1), curr(n+1);
        prev[0]=0;
        curr[0]=0;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(text1[i-1]!=text2[j-1]){
                    curr[j]=max(curr[j-1],prev[j]);
                }
                else{
                    curr[j]=1+prev[j-1];
                }
            }
            prev=curr;
        }
        return prev[n];
    }
public:
    int minInsertions(string s) {
        string rev=s;
        reverse(s.begin(),s.end());
        int lcs= longestCommonSubsequence(rev,s);
        return s.size()-lcs;
    }
};
