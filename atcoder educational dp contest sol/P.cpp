//https://atcoder.jp/contests/dp/tasks/dp_p

//please revise this

#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

pair<long long,long long> dfs(int node,vector<vector<int>>& adj ,vector<int> &vis){
    
    long long white=1;
    long long black=1;
    vis[node]=1;
    for(auto it:adj[node]){
      if(!vis[it]){
          auto [w,b]= dfs(it,adj,vis);
          white= white* (w+b)%mod;
          black= black* (w)%mod;
      }
        
    }
    return {white,black};
}
int main() {

	int n;
	cin>>n;
	vector<vector<int>> adj(n+1);
	adj[0]={0};
	for(int i=1;i<=n-1;++i){
	    int x,y;
	    cin>>x>>y;
	    adj[x].push_back(y);
	    adj[y].push_back(x);
	  
	}
	vector<int> vis(n+1,0);
	vis[0]=1;
 
	//white=0; black=1;
	auto [w,b]= dfs(1,adj,vis);
	cout<<(w+b)%mod<<endl;
}
