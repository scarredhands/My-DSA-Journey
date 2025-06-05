//https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
//steps- 1. sort to to find the 1st scc comp ele
//2. reverse the graph
//3. do dfs on all nodes to find no. od scc

//kosaraju is used to find strongly connected comp. 
// what is scc-A component is called a Strongly Connected Component(SCC) only if for every possible pair of vertices (u, v) inside that component, u is reachable from v and v is reachable from u.

//tc=O(V+E)
//SC= O(V+E)

class Solution {
  public:
    void topo(int node,vector<vector<int>> &adj,stack<int> &st,vector<int>&vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(vis[it]==0){
                topo(it,adj,st,vis);
            }
        }
        st.push(node);
    }
     void dfs(int node,vector<vector<int>> &adj,vector<int>&vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(vis[it]==0){
                dfs(it,adj,vis);
            }
        }
        
    }
    int kosaraju(vector<vector<int>> &adj) {
        stack<int> st;
        int v=adj.size();
        vector<int> vis(v,0);
        for(int i=0;i<v;++i){
            if(!vis[i]){
                topo(i,adj,st,vis);
            }
        }
        
        //reverse the graph
        vector<vector<int>> adjT(v);
        for(int i=0;i<v;++i){
            for(int j=0;j<adj[i].size();++j){
                adjT[adj[i][j]].push_back(i);
            }
        }
        int ans=0;
        for(int i=0;i<v;++i){
            vis[i]=0;
        }
        while(!st.empty()){
            int first=st.top();
            st.pop();
            if(!vis[first]){
                ans++;
                dfs(first,adjT,vis);
                
            }
        }
        return ans;
    }
};
