//https://cses.fi/problemset/task/1637

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1, 1e9);
    dp[0]=0;
    for(int i=1;i<=n;++i){
        string s=to_string(i);
        for(auto c:s){
            int j= c-'0';
            if(j>0){
                dp[i]= min(dp[i],dp[i-j]+1);
            }
        }
    }
    cout<<dp[n]<<endl;
}


	
	


