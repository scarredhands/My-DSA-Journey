// find the shortest path between the vertex 1 and the vertex n, and if the path does not exist then return a list consisting of only -1.

// Topmost element of the priority queue is with minimum distance value.


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        
       
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        } 
        //  { dist, node }.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        
        vector<int> dist(n + 1, 1e9), parent(n + 1); 
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        dist[1] = 0;

      
        pq.push({0, 1});
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

         
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});

                  
                    parent[adjNode] = node;
                }
            }
        }

        // If distance to a node could not be found, return an array containing -1.
        if (dist[n] == 1e9)
            return {-1};

       
        vector<int> path;
        int node = n;

        // Iterate backwards from destination to source through the parent array.
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        
// Since the path stored is in a reverse order, we reverse the array
 reverse(path.begin(), path.end());
        return path;
    }
};

int main()
{
    // Driver Code

    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, 
    {3, 5, 1}};
    Solution obj;
    vector<int> path = obj.shortestPath(V, E, edges);

    for (int i = 0; i < path.size(); i++)
    {

        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}
