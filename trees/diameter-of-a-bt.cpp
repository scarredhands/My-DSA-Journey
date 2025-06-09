//https://leetcode.com/problems/diameter-of-binary-tree/

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
    int dia(TreeNode* node,int &maxi){
        if(node==nullptr){
            return 0;
        }
        int lh=dia(node->left,maxi);
        int rh=dia(node->right,maxi);
        maxi=max(maxi,lh+rh);
        return 1+ max(lh,rh);
        

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        dia(root,ans);
        return ans;
    }
};
