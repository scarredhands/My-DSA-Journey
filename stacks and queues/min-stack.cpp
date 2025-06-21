//https://leetcode.com/problems/min-stack/

//encoding technique used. ratt le bhai-
//if val<mini => push the encoded val that is=> 2*val-mini => then val is newMin and mini is prevMin
//while popping if top <mini then pop it and change mini to prevMin by 
//decoding=> 2*mini-x
//in top if top value is less than mini then its the encoded val so return mini in that case

class MinStack {
private:
  stack<long long> st;
  long long mini=LLONG_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else if(val>mini){
            st.push(val);
        }
        else{
            long long encoded= 2*(long long)val- mini;
            mini=val;
            st.push(encoded);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x=st.top();
        st.pop();
        if(x<=mini){
           mini=2*mini-x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x=st.top();
        if(x<=mini){
            return mini;
            
        }
        return x;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
