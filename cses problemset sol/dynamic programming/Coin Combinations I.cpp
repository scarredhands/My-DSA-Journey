
//https://cses.fi/problemset/task/1635


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ;int x;
    cin>>n>>x;
    vector<int> arr(n);
    for(auto &it:arr){
        cin>>it;
    }
    int mod=1e9+7;
    vector<int> dp(x+1,0);
    dp[0]=1;
    for(int j=1;j<=x;++j){
        for(int i=1;i<=n;++i){
            if(j>=arr[i-1]){
                dp[j]=(dp[j]+dp[j-arr[i-1]])%mod;
            }
        }
    }
    cout<<dp[x]<<endl;
    
	

	}
	
	


