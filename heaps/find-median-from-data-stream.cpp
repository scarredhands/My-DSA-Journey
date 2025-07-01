//https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:

   priority_queue<int> left;
   priority_queue<int,vector<int>,greater<int>> right;

    MedianFinder() {

    }
    
    void addNum(int num) {
       if(left.empty() && right.empty()){
        left.push(num);
       }
       else if(!left.empty()  ){
        
        if(num>=left.top()){
            right.push(num);
        }
        else{
            left.push(num);
        }
       }
       else if(!right.empty()){
        if(num<right.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }
        
       }
      

       if(abs(int(right.size()-left.size()))>1){
        if(left.size()>right.size()){
            right.push(left.top());
            left.pop();
        }
        else{
            left.push(right.top());
            right.pop();
        }
       }
    }
    
    double findMedian() {
        double ans;
        if(left.size()==right.size()){
            ans= (left.top()+right.top())/2.0;
        }
        else{
            ans= (left.size()>right.size()) ? left.top(): right.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
