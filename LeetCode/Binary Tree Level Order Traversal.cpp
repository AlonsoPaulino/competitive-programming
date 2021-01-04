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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if (!root) return ans;
        
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            int lvl = u.first;
            TreeNode* node = u.second;
            
            int sz = (int) ans.size();
            if (sz <= lvl) {
                ans.push_back(vector<int>());
            }
            ans[lvl].push_back(node->val);   
            
            if (node->left) {
                q.push({lvl + 1, node->left});
            }
            if (node->right) {
                q.push({lvl + 1, node->right});
            }
        }
        return ans;
    }
};