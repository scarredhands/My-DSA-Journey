//https://leetcode.com/problems/shortest-path-in-binary-matrix/
//level wise traversal to find shortest path using bfs imp algo. do revise

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        int level=1;
        q.push({0,0});
        int drow[]={-1,0,1,0,-1,-1,1,1};
        int dcol[]={0,1,0,-1,1,-1,1,-1};
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        while(!q.empty()){
            int l= q.size();
            for(int i=0;i<l;++i){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(r==n-1 && c==n-1){
                    return level;
                }
                for(int j=0;j<8;++j){
                    int nrow=r+drow[j];
                    int ncol= c+ dcol[j];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==0){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
            level++;
        }
        return -1;

    }
};
