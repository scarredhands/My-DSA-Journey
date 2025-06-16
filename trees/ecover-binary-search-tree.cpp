//https://leetcode.com/problems/recover-binary-search-tree/
//tc=O(n)
//sc= O(1) = we r not counting the aux staxk space fro recursion calls.
//very imp...revise this

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
class Solution {
public:
    TreeNode* first=nullptr;
    TreeNode* second=nullptr;
    TreeNode* prev=nullptr;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
         if(prev && prev->val>=root->val){
            if(!first){
                first=prev;
                
            }
            second=root;
         
        }
        
            prev=root;
        
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        
        TreeNode* prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && second){
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
       
        }
       
        
    
    }
};
