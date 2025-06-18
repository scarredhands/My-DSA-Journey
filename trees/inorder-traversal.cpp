//https://leetcode.com/problems/binary-tree-inorder-traversal/
//tc= O(n)
//sc= O(h) where h=height of the tree

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
    //left, root,right;
    void helper(TreeNode* root,vector<int>&ans){
        if(root!=nullptr){
            helper(root->left,ans);
            ans.push_back(root->val);
            helper(root->right,ans);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};
