//https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
private:
   stack<int> st1,st2;
   void swapping(stack<int> &s1,stack<int> &s2){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    else{
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
   }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(st1.size()>0){
            st2.push(st1.top());
            st1.pop();
        }
        int val=st2.top();
        st2.pop();
        swapping(st1,st2);
        return val;
    }
    
    int peek() {
         while(st1.size()>0){
            st2.push(st1.top());
            st1.pop();
        }
        int val=st2.top();
        swapping(st1,st2);
        return val;
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
