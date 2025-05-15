//https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x;
	cin>>n>>x;
	vector<int> arr(n);
	for(int i=0;i<n;++i){
	    cin>>arr[i];
	}
	int INF=1e9;
	vector<vector<int>> dp(n+1,vector<int>(x+1,INF-1));
	for(int i=0;i<=n;++i){
	    dp[i][0]=0;
	}
	for(int i=1;i<=n;++i){
	    for(int j=0;j<=x;++j){
	        if(arr[i-1]>j){
	            dp[i][j]=dp[i-1][j];
	        }
	        else{
	            dp[i][j]= min(1+ dp[i][j-arr[i-1]],dp[i-1][j]);
	        }
	    }
	}
	if(dp[n][x]==INF-1){
	    dp[n][x]=-1;
	}
	cout<<dp[n][x]<<endl;

}
