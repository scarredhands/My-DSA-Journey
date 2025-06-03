//https://leetcode.com/problems/accounts-merge/

//solve this again.

class DisjointSet{
    vector<int> parent,rank;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<n;++i){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]= findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v= findUPar(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
             parent[ulp_u]=ulp_v;
        }
        else{
             parent[ulp_v]=ulp_u;
             rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mpp;
        int n=accounts.size();
        DisjointSet ds(n);
        for(int i=0;i<n;++i){
            int size=accounts[i].size();
            for(int j=1;j<size;++j){
                if(mpp.find(accounts[i][j])==mpp.end()){
                    mpp[accounts[i][j]]=i;
                }
                else{
                    ds.unionByRank(i,mpp[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> temp(n);
        for(auto it:mpp){
            string mail=it.first;
            int node=ds.findUPar(it.second);
            temp[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;++i){
            if(temp[i].size()==0) continue;
            sort(temp[i].begin(),temp[i].end());
            vector<string> temp2;
            temp2.push_back(accounts[i][0]);
            for(auto it:temp[i]){
                temp2.push_back(it);
            }
            ans.push_back(temp2);
        }
     return ans;
    }
};
