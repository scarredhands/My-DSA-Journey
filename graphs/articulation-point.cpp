//https://www.geeksforgeeks.org/problems/articulation-point2616/1
//revise this

class Solution {
  public:
   int timer=1;
   void dfs(int node,int parent,vector<int> adj[], vector<int> &low,vector<int> &tin, vector<int> & vis, set<int> &st){
       vis[node]=1;
       tin[node]=low[node]=timer;
       timer++;
       int child=0;
       for(auto it:adj[node]){
           if(vis[it]==0){
               child++;
               dfs(it,node,adj,low,tin,vis,st);
               low[node]=min(low[node],low[it]);
               if(low[it]>=tin[node] && parent!=-1){
                   st.insert(node);
               }
              
           }
            else{
                   low[node]=min(low[node],tin[it]);
               }
       }
       if(child>1 && parent==-1){
           st.insert(node);
       }
       
   }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        vector<int> low(V);
        vector<int> tin(V);
        vector<int> vis(V,0);
        set<int> st;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<V;++i){
            if(vis[i]==0){
                dfs(i,-1,adj,low,tin,vis,st);
            }
        }
        vector<int> ans;
        for(auto it:st){
            ans.push_back(it);
        }
        if(ans.size()==0) return {-1};
        return ans;
        
    }
};
