//https://leetcode.com/problems/divide-two-integers/

//point is if 3*7=21 => 3*(2**2 + 2**1 + 2**0) => u have to break the ans in powers of 2 and then check which powers are allowed to make 21.
//do revise

class Solution {

public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        // Convert to long to avoid overflow and take absolute values
        long long n=dividend,d=divisor,ans=0,shift=0;
        n=n<0?-n:n;
        d=d<0?-d:d;

        while(n>=d)
        {
           shift=0;
            // Double the divisor until it's larger than dividend
           while(n>=d<<(shift+1))
               shift++;
            ans+=1<<shift;
            n-=(d<<shift);  
        }

        // Apply sign
        return (dividend<0 ^ divisor<0)?-ans: ans;
    }
};
