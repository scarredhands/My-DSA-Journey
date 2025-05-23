//https://leetcode.com/problems/minimum-window-substring/
//https://www.youtube.com/watch?v=WJaij9ffOIY

class Solution {
public:
    string minWindow(string s, string t) {
        if(s==t){
            return s;
        }
        unordered_map<char,int> mpp;
        for(auto it:t){
            mpp[it]++;    //preset
        }
        int mini=INT_MAX;
        int start=-1;
        int l=0;
        int r=0;
        int n=s.size();
        int count=0;
        while(l<n && r<n){
            if(mpp[s[r]]>0){
                count++;
            }
            mpp[s[r]]--;
            while(count==t.size() && l<n){
                if(mini>(r-l+1)){
                    mini=r-l+1;
                    start=l;
                }
                mpp[s[l]]++; //removing this so ++, weird ik
                if(mpp[s[l]]>0){ //means its come back to preset pos
                    count--; 
                }
                l++;

            }
            r++;
        }
       if(start==-1){
        return "";
       }
       return s.substr(start,mini);
    }
};
