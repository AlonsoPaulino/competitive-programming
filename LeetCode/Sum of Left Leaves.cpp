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
    int ans = 0;
public:
    void dfs(int dir, TreeNode* x) {
        if (x->left == NULL && x->right == NULL && dir == 1) ans += x->val;
        if (x->left != NULL) dfs(1, x->left);
        if (x->right != NULL) dfs(0, x->right);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (root != NULL) dfs(0, root);
        return ans;
    }
};
