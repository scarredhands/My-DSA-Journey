//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
//again solve

class Solution {
private:
   int solve(vector<int>& cuts, int i, int j,vector<vector<int>> &memo){
    if(j-i<=1) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
    int mini=INT_MAX;
    for(int k=i+1;k<j;++k){
        int temp=solve(cuts,i,k,memo) + solve(cuts,k,j,memo)+ cuts[j]-cuts[i];
        mini=min(mini,temp);
    }
    return memo[i][j]= mini;
   }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> memo(m,vector<int>(m,-1));
        return solve(cuts,0,cuts.size()-1,memo);
    }
};
