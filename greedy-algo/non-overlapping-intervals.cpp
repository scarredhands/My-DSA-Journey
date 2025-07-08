//https://leetcode.com/problems/non-overlapping-intervals/
//plz solve this again without seeing the sol
//tc= O(N)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt=1;
        sort(intervals.begin(),intervals.end(),[](vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });
        int n = intervals.size();
        int endTime=intervals[0][1];
        for(int i=1;i<n;++i){
            if(intervals[i][0]>=endTime){
                cnt++;
                endTime=intervals[i][1];
            }
        }

         
        return n-cnt;
    }
};
