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
    int solve(TreeNode* x) {
        if (x == NULL) return 0;
        int a = solve(x->left);
        int b = solve(x->right);
        if (a == 0) x->left = NULL;
        if (b == 0) x->right = NULL;
        return a + b + x->val > 0 ? 1 : 0;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        int x = solve(root);
        if (x == 0) return NULL;
        return root;
    }
};
