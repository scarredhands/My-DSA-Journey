//https://www.geeksforgeeks.org/problems/rod-cutting0840/1

// using technique of unbounded knapsack problem
// time complexity= O(n^2)
//space complexity= O(n^2)

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n=price.size();
       vector<vector<int>> dp(n+1,vector<int>(n+1,0));
       for(int i=1;i<=n;++i){ //rod cut length
           for(int j=1;j<=n;++j){ //total rod length=j
               if(i>j){
                   dp[i][j]=dp[i-1][j];
               }
               else{
                   dp[i][j]= max(dp[i-1][j],price[i-1]+ dp[i][j-i]);
               }
           }
       }
       return dp[n][n];
       
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
