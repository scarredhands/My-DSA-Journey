//https://leetcode.com/problems/count-complete-tree-nodes/

//imp thing is reducing time complexity to O(logN)
//sc= O(logN)

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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        if(lh==rh) return (1<<lh) -1;
        return 1+ countNodes(root->left) +countNodes(root->right);
    }

    int leftHeight(TreeNode* node){
        if(node==nullptr) return 0;
        int h=0;
        while(node){
            h++;
            node=node->left;
        }
        return h;
    }
        int rightHeight(TreeNode* node){
        if(node==nullptr) return 0;
        int h=0;
        while(node){
            h++;
            node=node->right;
        }
        return h;
    }
};
