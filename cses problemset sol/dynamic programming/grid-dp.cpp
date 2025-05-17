//https://cses.fi/problemset/task/1638/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<vector<char>> arr(n,vector<char>(n));
	vector<vector<int>> dp(n,vector<int>(n,0));
    int mod= 1e9 +7;
	for(int i=0;i<n;++i){
	    for(int j=0;j<n;++j){
	       cin>>arr[i][j];
	    }
	}
	
	 if(arr[0][0] !='*'){
        dp[0][0]=1;
  }
	for(int i=0;i<n;++i){
	    for(int j=0;j<n;++j){
	      if(arr[i][j]=='*'){
	          continue;
	      }
	      if (i>0) dp[i][j]=(dp[i-1][j] +dp[i][j])%mod;
	      if(j>0) dp[i][j]=(dp[i][j]+ dp[i][j-1])%mod;
	    }
	}
	cout<<dp[n-1][n-1];
	

}
