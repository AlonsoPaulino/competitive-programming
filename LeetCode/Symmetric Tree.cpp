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
    bool validate(TreeNode* a, TreeNode* b) {
        if (a == NULL && b == NULL) return true;
        if (a == NULL || b == NULL) return false;
        if (a->val == b-> val) {
            bool x = validate(a->left, b->right);
            bool y = validate(a->right, b->left);
            return x && y;
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return validate(root->left, root->right);
    }
};
