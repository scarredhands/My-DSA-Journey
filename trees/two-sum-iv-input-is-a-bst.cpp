//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
//tc= O(N)
//sc= O(height)*2
//must revise

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator{
    
    stack<TreeNode*> st;
    bool reverse=true;
public:
  BSTIterator(TreeNode* root,bool isReverse){
    reverse=isReverse;
    pushAll(root);
  }
    void pushAll(TreeNode* node){

        while(node){
            st.push(node);
            if(reverse==true){
                node=node->right;
            }
            else{
                node=node->left;
            }
        }
        
    }

    int next(){
        TreeNode * node=st.top();
        st.pop();
        if(reverse){
            pushAll(node->left);
        }
        else{
            pushAll(node->right);
        }
        return node->val;
    }
};

class Solution {

public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l= BSTIterator(root,false);
        BSTIterator r= BSTIterator(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            if(i+j<k){
                i=l.next();
            }
            else{
                j=r.next();
            }
        }
        return false;
    }
};
