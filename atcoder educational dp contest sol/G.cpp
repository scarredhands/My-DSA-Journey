//https://atcoder.jp/contests/dp/tasks/dp_g

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	vector<int> indegree(n+1,0);
	vector<vector<int>> adj(n+1);
	for(int i=0;i<m;++i){
	    int x,y;
	    cin>>x>>y;
	    adj[x].push_back(y);
	    indegree[y]++;
	}
	queue<int>q;

	for(int i=1;i<=n;++i){
	    if(indegree[i]==0){
	        q.push(i);
	     
	    }
	}
	vector<int> topo;
	vector<int> dp(n+1);
	dp[0]=0;
	dp[1]=0;
	while(!q.empty()){
	    int node=q.front();
	    q.pop();
 topo.push_back(node);
	    for(auto it:adj[node]){
             dp[it]=max(dp[it],dp[node]+1);
	            indegree[it]--;
	        if(indegree[it]==0){
	            q.push(it);
	        
	        }
	       
	    }
	}

    int ans=0;
    for(int i=0;i<n+1;++i){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;

}
