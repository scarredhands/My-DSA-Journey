//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/1660647334/
//tc= O(N)
//sc= O(N)
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        bool left=true;
        if(root) q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> subAns(size);
            for(int i=0;i<size;++i){
                TreeNode* node=q.front();
                q.pop();
                int index= left? i: size-i-1;
                subAns[index]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            left=!left;
            ans.push_back(subAns);

        }
        return ans;
    }
};
