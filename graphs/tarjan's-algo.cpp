//https://leetcode.com/problems/critical-connections-in-a-network/
//tarjan's Algo..plz revise
//TC= O(V+ 2E)
//sc= O(3N + V+2E)

//tarjan's algo is used for finding critical bridges in a graph
//Any edge in a component of a graph is called a bridge when the component is divided into 2 or more components if we remove that particular edge.


class Solution {
public:
   int timer=1;
    void dfs(int node,int parent,vector<int> &vis, vector<int>& low, vector<int> &tin, vector<vector<int>> &ans, vector<int> adj[]){
        vis[node]=1;
        low[node]=tin[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent) continue; //taaki same path pe wapis na jaye
            if(vis[it]==0){
                dfs(it,node,vis,low,tin,ans,adj);
                low[node]=min(low[it],low[node]);
                if(low[it]>tin[node]){
                    ans.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<int> vis(n,0);
        vector<int> low(n);
        vector<int> tin(n);
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1,vis,low,tin,ans,adj);
        return ans;
    }
};
