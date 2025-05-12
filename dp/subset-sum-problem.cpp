
//https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include <bits/stdc++.h>
using namespace std;




class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<bool>> dp(arr.size()+1,vector<bool>(sum+1,false));
        
       dp[0][0]=true;        
        for(int i=1;i<arr.size()+1;i++){
            for(int j=0;j<=sum;++j){
                if(arr[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[arr.size()][sum];
        
    }
};




int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

