//https://leetcode.com/problems/greatest-common-divisor-of-strings/submissions/1711303152/

class Solution {
private:
      int gcd(int a, int b){
        return b==0 ? a: gcd(b,a%b);
      }
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1) return "";
        int gcdLen= gcd(str1.size(),str2.size());
        return str1.substr(0,gcdLen);

    }
};
