//https://leetcode.com/problems/binary-tree-maximum-path-sum/
//very very imp. must revise.
//tc= O(N)


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
    int helper(TreeNode* root,int &maxi){
          if(root==nullptr){
            return 0;
        }
       int ls=max(0,helper(root->left,maxi));
       int rs=max(0,helper(root->right,maxi));
       maxi=max(maxi,ls+rs+root->val);
       return root->val + max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
      int ans=-1000;
      helper(root,ans);
      return ans;
    }
};
