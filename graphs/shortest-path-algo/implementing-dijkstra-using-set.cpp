//using set to implement dijkstra


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int> dis(V,INT_MAX);
        //pair= {dist,node}
        set<pair<int,int>> s;
        s.insert({0,src});
        dis[src]=0;
        vector<pair<int,int>> adj[V];
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
        while(!s.empty()){
            auto it= *(s.begin());
            int node=it.second;
            int d=it.first;
            s.erase(it);
            for(auto it:adj[node]){
                int node2=it.first;
                int w=it.second;
                if(d+w<dis[node2]){
                   
                    //very imp part might forget is that to check for erasing from
                    //the set
                    if(dis[node2]!=INT_MAX){
                            s.erase({dis[node2],node2});
                    }
                     dis[node2]=d+w;
                    
                    s.insert({dis[node2],node2});
                }
            }
        }
        return dis;
        
        
    }
};
