//https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1

class Solution {
  public:
    int setBit(int n) {
        int p=1;
        int ans=n;
        while(n>0){
            if((n&1)==0){
               break;
            }
            p*=2;
            n=(n>>1);
        }
        return ans+p;
        
    }
};
