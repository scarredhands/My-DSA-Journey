//https://www.geeksforgeeks.org/problems/set-bits0143/1

class Solution {
  public:
    int setBits(int n) {
        int cnt=0;
        while(n>0){
            if((n&1)==1){
                cnt++;
            }
            n=(n>>1);
        }
        return cnt;
        
    }
};
