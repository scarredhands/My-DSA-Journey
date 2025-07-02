//https://atcoder.jp/contests/dp/tasks/dp_e

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,weight;
    cin>>n>>weight;
    vector<int> w(n);
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>w[i]>>v[i];
    }
    vector<vector<long long>> dp(n+1,vector<long long>(1e5+1));
    for(int i=0;i<=n;++i){
        dp[i][0]=0;
    }
    for(int j=1;j<=1e5;++j){
        dp[0][j]=INT_MAX;
    }
    //dp[i][j]= size of arr is i and j is value and dp[i][j] means min weight.
    for(int i=1;i<=n;++i){
        for(int j=1;j<=1e5;++j){
            if(v[i-1]>j){
                dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]= min(dp[i-1][j], w[i-1]+dp[i-1][j-v[i-1]]);
                }
        }
    }
for(int i=1e5;i>=0;--i){
        if(dp[n][i]<=weight){
            cout<<i<<endl;
            break;
        }
    }
    

}
