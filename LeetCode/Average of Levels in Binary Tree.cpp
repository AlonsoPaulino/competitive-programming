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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == NULL) return vector<double>();
        
        vector<double> ans;
        vector<int> sz;
    
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        ans.push_back(root->val);
        sz.push_back(1);
        
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            int lvl = u.first;
            auto node = u.second;
            
            int n = (int) ans.size();
            if (lvl < n) {
                ans[lvl] += node->val;
                sz[lvl]++;
            } else {
                ans.push_back(node->val);
                sz.push_back(1);
            }
            
            if (node->left) q.push({lvl + 1, node->left});
            if (node->right) q.push({lvl + 1, node->right});
        }
        
        int n = (int) ans.size();
        for (int i = 0; i < n; ++i) {
            ans[i] /= (double) sz[i];
        }
        
        return ans;
    }
};
