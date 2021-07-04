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
    vector<vector<int>> ans;
public:
    int solve(TreeNode* root) {
        if (root == NULL) return -1;
        
        int ld = solve(root->left);
        int rd = solve(root->right);
        
        int depth = max(ld, rd) + 1;
        
        if (ans.size() > depth) {
            ans[depth].push_back(root->val);
        } else {
            ans.push_back({ root->val });
        }
        
        return depth;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        solve(root);
        return ans;
    }
};
