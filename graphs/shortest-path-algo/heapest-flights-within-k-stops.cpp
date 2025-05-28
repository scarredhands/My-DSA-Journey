//https://leetcode.com/problems/cheapest-flights-within-k-stops/

//mindblowing problem
// you have to give priority to stops make pq of type {stop,dis,node}

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,src});
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        while(!pq.empty()){
            auto it=pq.top();
            int d=it[1];
            int stop=it[0];
            int node=it[2];
            pq.pop();
            // if(node==dst){
            //     return d;
            // }
            if(stop>k) continue;
            for(auto it: adj[node]){
                int node2=it.first;
                int w=it.second;
                if(w+d<dis[node2]){
                     pq.push({stop+1,d+w,node2});
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
