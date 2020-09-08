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
    int ans;
public:
    void solve(TreeNode* node, int x) {
        if (node->left == NULL && node->right == NULL) {
            ans += x;
            return;
        }
        if (node->left != NULL) solve(node->left, (x << 1) + node->left->val);
        if (node->right != NULL) solve(node->right, (x << 1) + node->right->val);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if (root == NULL) return 0;
        solve(root, root->val);
        return ans;
    }
};