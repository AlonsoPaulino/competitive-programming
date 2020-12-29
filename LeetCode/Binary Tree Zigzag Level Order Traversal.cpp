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
        vector<vector<int>> ans;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty() && root) {
            auto u = q.front(); q.pop();
            TreeNode* node = u.second;
            int n = (int) ans.size();
            int h = u.first;
            if (h >= n) {
                vector<int> v;
                v.push_back(node->val);
                ans.push_back(v);
            } else {
                ans[h].push_back(node->val);  
            }
            if (node->left) q.push({h + 1, node->left});
            if (node->right) q.push({h + 1, node->right});
        }
        for (int i = 0; i < (int) ans.size(); ++i) {
            if (i & 1) {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};