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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* ans = new TreeNode(v, root, NULL);
            return ans;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            auto u = node.first;
            int x = node.second;
            
            if (x + 1 == d) {
                u->left = new TreeNode(v, u->left, NULL);
                u->right = new TreeNode(v, NULL, u->right);
            } else {
                if (u->left) q.push({u->left, x + 1});
                if (u->right) q.push({u->right, x + 1});
            }
        }
        
        return root;
    }
};
