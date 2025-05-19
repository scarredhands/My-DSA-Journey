https://leetcode.com/problems/palindrome-partitioning/submissions/1638597391/

class Solution {
public:
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;
        bool ans= true;
        while(i<=j){
            if(s[i]!=s[j]){
                ans=false;
                break;
            }
            i++;
            j--;
        }
        return ans;
    }

    void isPartition(string s,int i,int j,vector<vector<string>> &ans, vector<string> &subset){
        if(i>j){
            ans.push_back(subset);
            return;
        }
        
        for(int k=i;k<=j;++k){
            string temp= s.substr(i,k-i+1);
            if(isPalindrome(temp)){
                subset.push_back(temp);
                isPartition(s,k+1,j,ans,subset);
                subset.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> subset;
        isPartition(s,0,s.size()-1,ans,subset);
        return ans;
    }
};
