//https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
   void dfs(int node,vector<int> adj[],stack<int> &st,vector<int>&vis){
       vis[node]=1;
       for(auto it: adj[node]){
           if(!vis[it]){
               dfs(it,adj,st,vis);
           }
       }
       st.push(node);
   }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        stack<int> st;
        vector<int> adj[V];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(V,0);
        for(int i=0;i<V;++i){
            if(!vis[i]){
                dfs(i,adj,st,vis);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
