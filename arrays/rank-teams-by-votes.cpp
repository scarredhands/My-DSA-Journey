//https://leetcode.com/problems/rank-teams-by-votes/description/

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if(votes.size()==1) return votes[0];
        int n=votes.size();
        int m=votes[0].size();
        vector<vector<int>> rank(26,vector<int>(m+1,0));
        for(int j=0;j<m;++j) rank[votes[0][j]-'A'][m]=votes[0][j];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                --rank[votes[i][j]-'A'][j];
            }
        }

        sort(rank.begin(),rank.end());
        string ans="";
        for(int i=0;i<m;++i){
            ans+=rank[i][m];
        }
        return ans;
    }
};
