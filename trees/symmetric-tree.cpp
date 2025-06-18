//https://leetcode.com/problems/symmetric-tree/submissions/1660907974/
//very very imp. how to check if two trees are equal->this concept is used in this problem.

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
    bool isEqual(TreeNode* node1,TreeNode* node2){
        if(!node1 || !node2){
            return node1==node2;
        }
        return node1->val==node2->val && isEqual(node1->left,node2->right) && isEqual(node1->right,node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
       return  isEqual(root->left,root->right);
    }
};
