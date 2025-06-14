//https://leetcode.com/problems/delete-node-in-a-bst/
//tc= O(height)
//sc= O(1)

//concept is that pehle node search kro and jab mil jaye then uske left subtree ke righmost node pe right subtree laga do to maintain the condition of a bst.

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
    TreeNode* helper(TreeNode* node){
        if(node->right==nullptr){
            return node->left;
        }
        else if(node->left==nullptr){
            return node->right;
        }
        TreeNode* rightChild= node->right;
        TreeNode* rightMostOfLeft= findRightMost(node->left);
        rightMostOfLeft->right=rightChild;
        return node->left;

    }
    
    TreeNode* findRightMost(TreeNode* node){
        if(node->right==nullptr) return node;
        return findRightMost(node->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val==key) return helper(root);
        TreeNode * node=root;
        while(node){
            if(node->val<key){
                if(node->right && node->right->val==key){
                    node->right=helper(node->right);
                    return root;
                }
                else{
                   node= node->right;
                }
            }
            else{
                if(node->left && node->left->val==key){
                    node->left=helper(node->left);
                    return root;
                }
                else{
                    node=node->left;
                }
            }
        }
        return root;
    }
};
