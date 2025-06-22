//https://leetcode.com/problems/remove-k-digits/
//tc=O(N)
//sc=O(N)

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int cnt=0;
        for(int i=0;i<num.size();++i){
             while(!st.empty() && (st.top()-'0')>(num[i]-'0') && cnt<k){
                st.pop();
                cnt++;
             }
             st.push(num[i]);
        }
        while(!st.empty() && cnt<k){
            st.pop();
            cnt++;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int j=0;
        while(j<ans.size() && ans[j]=='0' ){
            j++; 
        }
        if(j==ans.size()){
            return "0";
        }
        string newAns(ans.begin()+j,ans.end());
        return newAns;
    }
};
