//https://atcoder.jp/contests/dp/tasks/dp_k

//k ka state is changing so it is the only variable.

#include <bits/stdc++.h>
using namespace std;

int main() {
     // Add these two lines for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;++i){
	    cin>>a[i];
	}
	vector<bool> dp(k+1,false);
	for(int i=1;i<=k;++i){
	    for(int j=0;j<n;++j){
	        if(a[j]<=i && !dp[i-a[j]]){
	      
	            dp[i]=true;
	            break;
	        
	    }
	    }
	}
	
	if(dp[k]){
	    cout<<"First"<<endl;
	}
	else{
	    cout<<"Second"<<endl;
	}

}
