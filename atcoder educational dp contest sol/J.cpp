//https://atcoder.jp/contests/dp/tasks/dp_j

//https://www.youtube.com/watch?v=M_r02oqyKgY&list=PL6h2Gn3JK5Lnew3sVMFp0sNWBOgsDo62x&index=18

//expectation of x= x.P(x);

//difficult hai


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> state(4,0);
    for(int i=0;i<n;++i){
        int cnt;
        cin>>cnt;
        state[cnt]++;
    }
    
    double dp[305][305][305];
    memset(dp,0,sizeof(dp));
    
    for(int k=0;k<=n;++k){
        for(int j=0;j<=n;++j){
            for(int i=0;i<=n;++i){
                if(i+j+k<=n){
                    if(i+j+k==0) continue;
                    double p1= i*1.0/n;
                    double p2= j*1.0/n;
                    double p3= k*1.0/n;
                    double p0= (n-(i+j+k))*1.0/n;
                    if(i>0) dp[i][j][k]+= p1*dp[i-1][j][k];
                    if(j>0) dp[i][j][k]+= p2*dp[i+1][j-1][k];
                    if(k>0) dp[i][j][k]+= p3*dp[i][j+1][k-1];
                    dp[i][j][k]+=1.0;
                   if(p0!=1) dp[i][j][k]/=(1-p0);
                    
                }
            }
        }
    }
    
    cout<<setprecision(10)<<dp[state[1]][state[2]][state[3]]<<endl;
    
    
}
