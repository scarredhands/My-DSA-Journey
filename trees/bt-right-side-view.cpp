//https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        //pair=node,row
        queue<pair<TreeNode*,int>>q;
        vector<int> ans;
        if(!root) return ans;
        //map=row,last ele in row
        map<int,int> mpp;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;++i){
                TreeNode* node=q.front().first;
                int r= q.front().second;
                q.pop();
                mpp[r]=node->val;
                if(node->left) q.push({node->left,r+1});
                if(node->right) q.push({node->right,r+1});
            }
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
