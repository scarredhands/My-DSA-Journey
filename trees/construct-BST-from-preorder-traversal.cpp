//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
//revise this again

//tc= O(N)
//sc= O(1)

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
    TreeNode* helper(vector<int> &preorder,int &i,int bound){
        if(i==preorder.size()|| preorder[i]>bound) return nullptr;
        TreeNode* node= new TreeNode(preorder[i++]);
        node->left=helper(preorder,i,node->val);
        node->right=helper(preorder,i,bound);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return nullptr;
        int i=0;
        return helper(preorder,i,INT_MAX);
    }
};
