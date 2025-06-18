//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
//tc=O(N)
//sc= O(N)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> q;
        if(!root) return;
        parent[root]=root;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> parent;
        markParents(root,parent);
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        while(!q.empty()){
            int dis=q.front().second;
            TreeNode* node=q.front().first;
            q.pop();
            if(dis==k) ans.push_back(node->val);
            if(node->left && !vis[node->left]){
                q.push({node->left,dis+1});
                vis[node->left]=true;
            }
            if(node->right && !vis[node->right]){
                q.push({node->right,dis+1});
                vis[node->right]=true;
            }
            if(parent[node] && !vis[parent[node]]){
                q.push({parent[node],dis+1});
                vis[parent[node]]=true;
            }
        }
        return ans;
    }
};
