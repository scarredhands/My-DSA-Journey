//https://leetcode.com/problems/kth-largest-element-in-a-stream/
//tc= O(log(k)) 
//sc= O(k)

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int large;
    KthLargest(int k, vector<int>& nums) {
        large=k;
        for(int i=0;i<nums.size();++i){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<large){
            pq.push(val);
        }
        else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
