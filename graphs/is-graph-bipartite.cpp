//https://leetcode.com/problems/is-graph-bipartite/
class Solution {
public:

    bool dfs(int node,int color,vector<vector<int>> &graph, vector<int> &vis){
        if(vis[node]==-1){
            vis[node]=color;
        }
        for(auto it: graph[node]){
            
                if(vis[it]==-1){
                   if( dfs(it,!color,graph,vis)==false){
                    return false;
                   };
              
                }
                else{
                    if(color==vis[it]){
                        return false;
                    }
                }
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> vis(v,-1);
        for(int i=0;i<v;++i){
            if(vis[i]==-1){
               if(dfs(i,0,graph,vis)==false) {
                return false;
               }
            }
        }
        return true;
        

    }
};
