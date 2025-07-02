//https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(3));
    for(int i=0;i<n;++i){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    for(int i=1;i<n+1;++i){
        for(int j=0;j<3;++j){
            dp[i][j]= arr[i-1][j] + max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
        }
    }
    
    int ans= max(dp[n][0],max(dp[n][1],dp[n][2]));
    cout<<ans<<endl;

}
