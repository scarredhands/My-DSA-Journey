//https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
//min-spanning-tree sum
//prim's algo


class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> vis(V,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int w=it.first;
            pq.pop();
            if(vis[node]==0){
                vis[node]=1;
                sum+=w;
                for(auto it:adj[node]){
                    pq.push({it[1],it[0]});
                }
            }
        }
        return sum;
        
    }
};