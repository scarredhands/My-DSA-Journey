//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution {
  public:
    void topoSort(int node,vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st){
        vis[node]=1;
        for(auto it: adj[node]){
            if(vis[it.first]==0){
                topoSort(it.first,adj,vis,st);
            }
        
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        stack<int> st;
        vector<pair<int,int>> adj[V];
        vector<int> vis(V,0);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        for(int i=0;i<V;++i){
            if(vis[i]==0){
                topoSort(i,adj,vis,st);
            }
        }
        vector<int> dis(V,-1);
        dis[0]=0;
        while(!st.empty()){
            int node= st.top();
            st.pop();
           if(dis[node]!=-1){
                for(auto it: adj[node]){
                int node2=it.first;
                int d=it.second;
                if(dis[node2]==-1){
                    dis[node2]=d+ dis[node];
                }
                else{
                    dis[node2]=min(dis[node2],d+dis[node]);
                }
            }
           }
        }
        return dis;
    }
};