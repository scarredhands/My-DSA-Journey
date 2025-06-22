//https://leetcode.com/problems/asteroid-collision/
//tc= O(N)
//sc= O(N)

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int> ans;
        stack<int>st2;
        for(int i=0;i<asteroids.size();++i){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && abs(st.top())<abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(asteroids[i])){
                    st.pop();
                }
                else if(st.empty()){
                    ans.push_back(asteroids[i]);
                }

            }
        }
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }
};
