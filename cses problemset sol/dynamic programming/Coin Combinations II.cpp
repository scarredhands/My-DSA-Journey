//https://cses.fi/problemset/task/1636/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    const int MOD = 1e9 + 7;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for(int i=1;i<=n;++i){ //order matter nhi karta so outer loop mein order/n le liya
        for(int j=0;j<=x;++j){ 
            if(arr[i-1]<=j){
                dp[j]=(dp[j]+dp[j-arr[i-1]])%MOD;
            }
        }
    }


    cout << dp[x] << endl;
}


	
	


