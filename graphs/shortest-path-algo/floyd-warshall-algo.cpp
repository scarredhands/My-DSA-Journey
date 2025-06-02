//https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

//floyd warshall algo- little bit like dp
//you have to go from node1 to node2 through all the nodes.
// used for finding shortest distance from multiple sources.
// for finding negative cycles using this algo, dist[i][i]<0 if there is a neg cycle otherwise dist[i][i]=0

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        const int mod=1e8;
        int n=dist.size();
        vector<vector<int>> ans(n,vector<int>(n,mod));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                for(int k=0;k<n;++k){
                  if(dist[j][i]==mod || dist[i][k]==mod){
                      dist[j][k]=dist[j][k];
                  }
                  else{
                        dist[j][k]= min(dist[j][i]+ dist[i][k],dist[j][k]);
                  }
                    
                   
                }
            }
        }
    }
};
