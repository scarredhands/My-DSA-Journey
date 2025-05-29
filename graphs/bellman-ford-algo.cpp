//https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
//helps finding neg cycle
//tc= O(V*E)

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        const int mod=1e8;
        vector<int> dis(V,mod);
        dis[src]=0;
        //relax all edges for v-1 times.
        for(int i=0;i<V-1;++i){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                if(dis[u]!=mod && dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                }
            }
        }
    
        //if after v-1 relaxations..another is possible then it contains a neg cycle
        for(auto it:edges){
             int u=it[0];
                int v=it[1];
                int w=it[2];
                if(dis[u]!=mod && dis[u]+w<dis[v]){

                    return {-1};
                }
        }
         
        return dis;
        
    }
};
