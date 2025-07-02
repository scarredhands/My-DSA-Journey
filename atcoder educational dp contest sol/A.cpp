//https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;++i){
	    cin>>arr[i];
	}
    vector<int> dp(n+1,0);
    dp[2]=abs(arr[1]-arr[0]);
    for(int i=3;i<n+1;++i){
        dp[i]=min(dp[i-1]+ abs(arr[i-2]-arr[i-1]), dp[i-2]+abs(arr[i-3]-arr[i-1]));
    }
    cout<<dp[n]<<endl;

}

