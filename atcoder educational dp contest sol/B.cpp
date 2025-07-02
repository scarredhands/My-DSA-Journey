//https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;++i){
	    cin>>arr[i];
	}
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    dp[1]=0;
    dp[2]=abs(arr[1]-arr[0]);
    for(int i=3;i<n+1;++i){
        int idx= (i<k)? i: k;
        for(int j=1;j<=idx;++j){
           if(i-j>=1){
                dp[i]=min(dp[i-j]+ abs(arr[i-j-1]-arr[i-1]),dp[i]);
           }
        }
    }
    cout<<dp[n]<<endl;

}
