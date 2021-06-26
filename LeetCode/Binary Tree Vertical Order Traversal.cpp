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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int>>();
        }
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            auto v = u.first;
            int x = u.second;
            m[x].push_back(v->val);
            if (v->left) q.push({v->left, x - 1});
            if (v->right) q.push({v->right, x + 1});
        }
        vector<vector<int>> ans;
        for (auto it: m) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
