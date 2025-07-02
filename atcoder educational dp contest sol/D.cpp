//https://atcoder.jp/contests/dp/tasks/dp_d

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
    vector<vector<long long>> dp(n+1,vector<long long>(weight+1));
    for(int i=0;i<=n;++i){
        for(int j=0;j<=weight;++j){
            if(j==0 || i==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;++i){
        for(int j=1;j<weight+1;++j){
            if(w[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(v[i-1]+ dp[i-1][j-w[i-1]], dp[i-1][j]);
            }
        }
    }
    
    cout<<dp[n][weight]<<endl;
}
