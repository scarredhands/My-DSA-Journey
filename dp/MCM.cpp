//https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int solve(vector<int> &arr, int i,int j,int n,vector<vector<int>> &dp){

        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=INT_MAX;
        for(int k=i;k<j;++k){
            int temp= solve(arr,i,k,n,dp) +solve(arr,k+1,j,n,dp) + arr[i-1]*arr[k]*arr[j];
            mini=min(mini,temp);
        }
        dp[i][j]=mini;
        return dp[i][j];
        
    }
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int i=1; int j=n-1;
        return solve(arr,i,j,n,dp);
        
    }
};



int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}
