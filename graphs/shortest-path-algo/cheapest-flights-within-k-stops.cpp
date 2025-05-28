//https://leetcode.com/problems/cheapest-flights-within-k-stops/

//mindblowing problem
// you have to give priority to stops make pq of type {stop,dis,node}
// have to use queue instead of pq cuz the stops are already sorted.
//edges= flights.size();

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<vector<int>> q;
        q.push({0,0,src});
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        while(!q.empty()){
            auto it= q.front();
            int d=it[1];
            int stop=it[0];
            int node=it[2];
            q.pop();
            // if(node==dst){
            //     return d;
            // }
            if(stop>k) continue;
            for(auto it: adj[node]){
                int node2=it.first;
                int w=it.second;
                if(w+d<dis[node2]){
                     q.push({stop+1,d+w,node2});
                     dis[node2]=d+w;
                }
                   
                
            }

        }
        if(dis[dst]!=INT_MAX){
            return dis[dst];
        }
        return -1;
    }
};
