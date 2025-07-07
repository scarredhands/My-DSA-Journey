// //https://leetcode.com/problems/valid-parenthesis-string/description/
//see both the approaches-

//1st one is not space optimised.

class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st1,st2;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                st1.push(i);
            }
            else if(s[i]=='*'){
                st2.push(i);
            }
            else{
                if(!st1.empty()){
                    st1.pop();
                }
                else if(!st2.empty()){
                    st2.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!st1.empty() && !st2.empty()){
            if(st1.top()>st2.top()){
                return false;
            }
            st1.pop();
            st2.pop();
        }
        return st1.empty();
    }
};

//2nd approach takes constant space
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                low++;   // one more unmatched '('
                high++;  // same
            } else if (ch == ')') {
                if (low > 0) low--;  // match with '('
                high--;              // whether matched or not
            } else { // '*'
                if (low > 0) low--;  // assume '*' as ')'
                high++;              // assume '*' as '('
            }
            
            if (high < 0) return false; // too many unmatched ')'
        }

        return low == 0; // all '(' must be matched in some valid way
    }
};
