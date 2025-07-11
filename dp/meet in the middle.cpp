//https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

//really different approach- meet in the middle
//revise again

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        int n=nums.size()/2;
        //left[i]= subset sums of all subsets having size i.
        vector<vector<int>> left(n+1), right(n+1);
        for(int mask=0;mask<(1<<n);++mask){
            int cnt=0   ; // count of ele in the subset
            int leftSum=0;
            int rightSum=0;
            for(int i=0;i<n;++i){
                if(mask & (1<<i)){
                    cnt++;
                    leftSum+=nums[i];
                    rightSum+=nums[n+i];
                }
            }
            left[cnt].push_back(leftSum);
            right[cnt].push_back(rightSum);
        }
        
        for(int i=0;i<n;++i){
            sort(right[i].begin(),right[i].end());
        }

        int res=min(abs(sum-2*left[n][0]), abs(sum-2*right[n][0]));

        for(int cnt=1;cnt<n;++cnt){
            for(auto &a:left[cnt]){
                int b= (sum- 2*a)/2;
                int rightCnt= n-cnt; //right cnt
                auto & v=right[rightCnt];
                auto it= lower_bound(v.begin(),v.end(),b);
                if(it!=v.end()){
                    res=min(res,abs(sum-2*(a+*it)));
                }
                if(it!=v.begin()){
                   
                    --it;
                    res=min(res,abs(sum-2*(a+*it)));
                }
            }
        }
        return res;

    }
};
