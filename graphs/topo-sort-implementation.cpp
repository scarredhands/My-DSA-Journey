//https://leetcode.com/problems/course-schedule-ii/submissions/1644175790/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> in(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
         for(int i=0;i<numCourses;++i){
            if(in[i]==0){
                q.push(i);
            }
         }
         vector<int> ans;
         while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }

         }
         if(ans.size()!=numCourses){
            return {};
         }
         return ans;

    }
};
