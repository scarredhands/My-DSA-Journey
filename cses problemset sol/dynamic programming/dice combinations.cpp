//https://cses.fi/problemset/task/1633


#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> dp(n+1,0);
	dp[0]=1;
	int mod=1e9+7;
	for(int i=1;i<=n;++i){
	    for(int j=1;j<=6;++j){
	       if(j<=i){
	           dp[i]=(dp[i-j] +dp[i])%mod;
	       }
	    }
	}
	cout<<dp[n]<<endl;
	}
	
	


