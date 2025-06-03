//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

// do revise how to form a graph

class DisjointSet{
    vector<int> parent,rank;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;++i){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(parent[node]==node){
            return node;
        }
         return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u= findUPar(u);
        int ulp_v= findUPar(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxr=INT_MIN;
        int maxc=INT_MIN;
        for(auto it:stones){
            maxr=max(maxr,it[0]);
            maxc=max(maxc,it[1]);
        }
        DisjointSet ds(maxr+maxc+1);
        unordered_map<int,int> mpp;
        for(auto it:stones){
            it[1]+=(maxr+1);
            int u=it[0];
            int v=it[1];
            mpp[u]=1;
            mpp[v]=1;

                ds.unionByRank(u,v);
        
            
        }
          int ans=0;
          for(auto it:mpp){
            if(ds.findUPar(it.first)==it.first && it.second){
                ans++;
            }
          }
          return n-ans;
       
    }
};
