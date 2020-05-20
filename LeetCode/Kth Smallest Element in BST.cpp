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
    int target;
    int ans = 0;
    
    void solve(TreeNode* node) {
        if (node == NULL) return;
        solve(node->left);
        if (--target == 0) ans = node->val; 
        solve(node->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        target = k;
        solve(root);
        return ans;
    }
};