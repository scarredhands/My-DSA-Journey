//https://atcoder.jp/contests/dp/tasks/dp_o

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	const int mod=1e9+7;
	vector<vector<int>> comp(n,vector<int> (n));
	for(int i=0;i<n;++i){
	    for(int j=0;j<n;++j){
	        cin>> comp[i][j];
	    }
	}
	vector<int> dp(1<<n,0);
	dp[0]=1;
	
	for(int s=0;s<(1<<n);++s){
	         int alreadyMatched= __builtin_popcount(s); //no. of 1s in the set== no. of men already matched
	    for(int w=0;w<n;++w){
	   
	        if(s&(1<<w) || !comp[alreadyMatched][w]){
	            continue;
	        }
	        
	        dp[s|(1<<w)]+=dp[s];
	        dp[s| (1<<w)]%=mod;
	    }
	}
	
	cout<<dp[(1<<n)-1]<<endl;

}
