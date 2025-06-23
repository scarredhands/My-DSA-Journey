//https://leetcode.com/problems/online-stock-span/

//tc=O(2N)
//sc=O(N)

class StockSpanner {
private:
   //pair={val,ind}
   stack<pair<int,int>> st;
   int ind;
public:
    StockSpanner() {
        ind=-1;
        while(!st.empty()){
            st.pop();
        }
    }
    
    int next(int price) {
        ind++;
        while(!st.empty() && price>=st.top().first){
            st.pop();
        }
        int pge=st.empty()?-1:st.top().second;
        int ans= ind- pge;
        st.push({price,ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
