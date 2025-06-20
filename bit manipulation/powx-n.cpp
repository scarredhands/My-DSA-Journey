//https://leetcode.com/problems/powx-n/submissions/1670777616/

//tc= O(logN)

class Solution {
public:
    double myP(double x, long long n){
        if(n==0){
            return 1;
        }
         if(n<0){
            return myP(1/x,-n);
        }
        if(n%2==0){
           return myP(x*x,n/2);
        }
        else{
            return x*(myP(x*x,(n-1)/2));
        }
    }
    double myPow(double x, int n) {
       return myP(x,long(n));
       
    }
};
