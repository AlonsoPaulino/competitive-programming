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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 != NULL && t2 != NULL) {
            return new TreeNode(
                t1->val + t2->val, 
                mergeTrees(t1->left, t2->left),
                mergeTrees(t1->right, t2->right)
            );
        } else if (t1 != NULL && t2 == NULL) {
            return new TreeNode(
                t1->val,
                mergeTrees(t1->left, NULL),
                mergeTrees(t1->right, NULL)
            );
        } else if (t1 == NULL && t2 != NULL) {
            return new TreeNode(
                t2->val,
                mergeTrees(NULL, t2->left),
                mergeTrees(NULL, t2->right)
            );
        } else {
            return NULL;
        }
    }
};
