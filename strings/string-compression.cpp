//https://leetcode.com/problems/string-compression/
//tc= O(N)
//sc= O(1)
//its like 3 pointers problem

class Solution {
public:
    int compress(vector<char>& chars) {
        int curr=0; //for modifying the array in place
        
        int i=0; // start ptr of the repeating char
       while(i<chars.size()){
        int len=1; //end ptr for the repeating char
         while(i+len<chars.size() && chars[i+len]==chars[i]){
            len++;
        }
        chars[curr++]=chars[i];
        if(len>1){
            for(auto ch: to_string(len)){
                chars[curr++]=ch;
            }
        }
        i+=len;
       }
       return curr; //new size of the array
    }
};
