//https://atcoder.jp/contests/dp/tasks/dp_n
//similar to mcm like finding intervals solving it

#include <bits/stdc++.h>
using namespace std;

long long getSum(int i ,int j, vector<long long> & prefix){
    return prefix[j+1]-prefix[i];
}
long long solve(vector<int> &arr, vector<vector<long long>> &dp, int i, int j,vector<long long >& prefix){
    if(i>=j){
        return 0;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
   long long mini=LLONG_MAX;
   for(int k=i;k<j;++k){
       long long temp = solve(arr,dp,i,k,prefix)+solve(arr,dp,k+1,j,prefix) + getSum(i,j,prefix);
        mini=min(mini,temp);
}
   dp[i][j]=mini;
   return dp[i][j];
   
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    vector<long long> prefix(n+1);
    prefix[0]=0;
    for(int i=1;i<=n;++i){
        prefix[i]=prefix[i-1]+arr[i-1];
    }
    vector<vector<long long>> dp(n,vector<long long>(n,-1));
    
    long long ans=solve(arr,dp,0,n-1,prefix);
    cout<<ans<<endl;
    

}
