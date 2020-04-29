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
    int ans = 0;
    
    int solve(TreeNode* root) {
        if (root == NULL) {
            return 0;   
        }
        int left = solve(root->left);
        int right = solve(root->right);
        int x = max(max(left, right) + root->val, root->val);
        ans = max(ans, max(x, left + right + root->val));
        root->val = x;
        return x;
    }
    
    int maxPathSum(TreeNode* root) {
        if (root != NULL) {
            ans = root->val;
            solve(root);
        }
        return ans;
    }
};