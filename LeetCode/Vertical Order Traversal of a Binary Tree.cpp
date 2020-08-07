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
    map<int, map<int, vector<int>>> m;
public:
    void dfs(TreeNode* node, int x, int y) {
        if (node == NULL) return;
        m[x][y].push_back(node->val);
        dfs(node->left, x - 1, y + 1);
        dfs(node->right, x + 1, y + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, 0);
        auto it = m.begin();
        while (it != m.end()) {
            auto mm = it->second;
            vector<int> arr;
            auto mmit = mm.begin();
            while (mmit != mm.end()) {
                auto aux = mmit->second;
                sort(aux.begin(), aux.end());
                for (auto i: aux) arr.push_back(i);
                ++mmit;
            }
            ans.push_back(arr);
            ++it;
        }
        return ans;
    }
};