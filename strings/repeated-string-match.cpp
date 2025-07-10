//https://leetcode.com/problems/repeated-string-match/

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated="";
        int cnt=0;
        while(repeated.size()<b.size()){
            repeated+=a;
           cnt++;
        }
         if(repeated.find(b)!=string::npos) return cnt;
         repeated+=a;
          if(repeated.find(b)!=string::npos) return cnt+1;
          return -1;
    }
};
