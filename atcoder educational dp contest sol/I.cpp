//https://atcoder.jp/contests/dp/tasks/dp_i

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<double> p(n);
	for(int i=0;i<n;++i){
	    cin>>p[i];
	}
	int leastHeads= n/2 +1;
	vector<vector<double>> dp(n+1,vector<double>(n+1));
	for(int i=0;i<=n;++i){
	    dp[i][0]=1; //0 heads i always possible
	}
	for(int j=1;j<n+1;++j){
	    dp[0][j]=0;
	}
	
	for(int i=1;i<=n;++i){
	    for(int j=1;j<=leastHeads;++j){
	        dp[i][j]= dp[i-1][j-1]*p[i-1] + dp[i-1][j]*(1-p[i-1]);
	    }
	}
	
	cout<<setprecision(10)<<dp[n][leastHeads]<<endl;

}
