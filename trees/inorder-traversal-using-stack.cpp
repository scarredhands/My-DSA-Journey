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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root==nullptr) return ans;
      
        while(true){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                if(st.empty()==true) break;
                TreeNode* node= st.top();
                ans.push_back(node->val);
                st.pop();
                root=node->right;
            }
        }
        return ans;
    }
};
