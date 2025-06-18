//https://leetcode.com/problems/maximum-width-of-binary-tree/?source=submission-ac
// revise this= each sub tree of a tree having val i will be of val 2*i+1, 2*i+2

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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long maxi=0;
        while(!q.empty()){
            int size=q.size();
            long long min_id=q.front().second;
            long long first,last;
            for(int i=0;i<size;++i){
                TreeNode* node=q.front().first;
                long long idx=q.front().second-min_id;
                if(i==0) first= idx;
                if(i==size-1) last=idx;
                q.pop();
                if(node->left) q.push({node->left,2*idx+1});
                if(node->right) q.push({node->right,2*idx+2});
            }
            maxi=max(maxi,last-first+1);
        }
        return maxi;
    }
};
