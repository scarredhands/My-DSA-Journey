//https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1

#include <bits/stdc++.h>
using namespace std;




class Solution {

  public:
    int minDifference(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(auto it:arr){
            sum+=it;
        }
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<n+1;++i){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;++i){
            for(int j=0;j<=sum;++j){
                if(arr[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<(sum/2+1);++j){
            if(dp[n][j]==true){
                mini=min(mini,abs(sum-2*j));
            }
        }
        return mini;
    }
};




int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
