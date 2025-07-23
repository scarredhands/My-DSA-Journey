//https://neetcode.io/problems/sum-of-two-integers?list=blind75

class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int carry= (a & b)<<1;  //shifting right as its carry
            a^=b;   //xor adds without carry
            b=carry;

        }
        return a;
    }
};
