// https://leetcode.com/problems/combination-sum/submissions/1635340022/

class Solution {
public:
    void sub(vector<int> & arr, int target, int n, vector<vector<int>>&ans, vector<int> & subset){
        if(target==0){
            ans.push_back(subset);
            return;
        }
        if(n==0 || target<0){
            return;
        }
        if(arr[n-1]<=target){
            subset.push_back(arr[n-1]);
            sub(arr,target-arr[n-1],n,ans,subset);
            subset.pop_back();
            sub(arr,target,n-1,ans,subset);
        }
        else{
            sub(arr,target,n-1,ans,subset);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> subset;
        sub(candidates,target,candidates.size(),ans,subset);
        return ans;
    }
};
