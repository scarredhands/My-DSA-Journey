//https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int inorder(TreeNode* node,int k,int &cnt){
        if(!node) return -1;
        int left=inorder(node->left,k,cnt);
        if (left!=-1) {
            return left;
        }
        cnt++;
        if(cnt==k) return node->val;
        return inorder(node->right,k,cnt);
       
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans=inorder(root,k,cnt);
        return ans;
    }
};
