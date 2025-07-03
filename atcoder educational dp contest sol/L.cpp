//https://atcoder.jp/contests/dp/tasks/dp_l

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    vector<vector<long long>> dp(3001,vector<long long>(3001,0));
    for(int i=0;i<n;++i){
        dp[i][i]=arr[i];
    }
    
    for(int length=2;length<=n;++length){
        for(int i=0;i<=n-length;++i){
            int j=i+length-1;
            dp[i][j]= max(arr[i]-dp[i+1][j], arr[j]-dp[i][j-1]);
        }
    }
    
    cout<<dp[0][n-1]<<endl;
}
