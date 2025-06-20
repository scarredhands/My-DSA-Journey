//https://leetcode.com/problems/count-primes/

//algo is sieve of eratosthenes. pls revise.
//tc= O(Nlog(logN)) - its a prime harmonic series.
//sc= o(N)

class Solution {
public:
    int countPrimes(int n) {
        //u have to do pre computation. in pre 1 means it is a prime no.
        vector<int> pre(n+1,1);
        
        for(int i=2;i<=sqrt(n);++i){
            if(pre[i]==1){
                for(int j=i*i;j<=n;j+=i){
                pre[j]=0; // 0 means its not prime
            }
            }
        }
        int cnt=0;
        for(int i=2;i<n;++i){
            if(pre[i]==1){
                cnt++;
            }
        }
        return cnt;
    }
};
