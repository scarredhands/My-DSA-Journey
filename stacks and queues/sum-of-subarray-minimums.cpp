//https://leetcode.com/problems/sum-of-subarray-minimums/

//samajh nhi aya

class Solution {
private:
    vector<int> findPSE(vector<int> & arr){
        int n=arr.size();
        stack<int> st;
        vector<int> pse(n);
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i]=st.empty() ? -1: st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> findNSE(vector<int>&arr){
        int n=arr.size();
        stack<int> st;
        vector<int> nse(n);

        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]= st.empty()? arr.size(): st.top();
            st.push(i);
        }
        return nse;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans=0;
        long long mod=1e9+7;
        vector<int> nse=findNSE(arr);
        vector<int> pse= findPSE(arr);
        for(int i=0;i<arr.size();++i){
            long long lWidth=i- pse[i];
            long long rWidth= nse[i]-i;

            ans=(ans+(lWidth*rWidth*1LL*arr[i])%mod)%mod;
        }
        return (int)ans;

    }
};
