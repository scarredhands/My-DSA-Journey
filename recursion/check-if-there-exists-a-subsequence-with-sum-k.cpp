//https://takeuforward.org/plus/dsa/problems/check-if-there-exists-a-subsequence-with-sum-k
#include <bits/stdc++.h>
using namespace std;

bool rec(int i, int k,vector<int> &nums,int sum){
        if(i==(nums.size())){
            if(sum==k){
                return true;
            }
            return false;
        }
        sum+=nums[i];
        bool l=rec(i+1,k,nums,sum);
        sum-=nums[i];
      bool r=rec(i+1,k,nums,sum);
      return (l+r);
       
    }   	
int main() {
 vector<int> arr= {4,3,9,2};
 int c=0;
bool ans=rec(0,10,arr,0);
cout<<ans<<endl;
 

  

}
