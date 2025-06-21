//https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        map<int, int> mpp; // value -> next greater value
        int n = nums.size();

        for (int i = 2 * n - 1; i >= 0; i--) {
            int val = nums[i % n];

            while (!st.empty() && st.top() <= val) {
                st.pop();
            }

            if (st.empty()) {
                mpp[i%n] = -1;
            } else {
                mpp[i%n] = st.top();
            }

            st.push(val);
        }

        vector<int> ans;
        for (int i=0;i<n;++i) {
            ans.push_back(mpp[i]); // overwrite okay as per your intent
        }

        return ans;
    }
};
