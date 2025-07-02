//https://atcoder.jp/contests/dp/tasks/dp_h

#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w;
    const int mod= 1e9+7;
    cin>>h>>w;
    vector<vector<char>> mat(h,vector<char>(w));
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
           cin>>mat[i][j];
        }
    }
    
    vector<vector<int>> dp(h,vector<int>(w,0));
    dp[0][0]=1;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            if(i==0 && j==0) continue;
            if(i==0 && mat[i][j]=='.'){
                dp[i][j]=dp[i][j-1]%mod;
            }
            else if(j==0 && mat[i][j]=='.'){
                dp[i][j]=dp[i-1][j]%mod;
            }
            else if(mat[i][j]=='.'){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }
    
    cout<<dp[h-1][w-1]<<endl;

}
