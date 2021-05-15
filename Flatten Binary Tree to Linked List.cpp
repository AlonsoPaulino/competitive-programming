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
    TreeNode* p = NULL;
public:
    
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        
        if (p != NULL) {
            p->right = root;
            p->left = NULL;
        }
        
        p = root;
        
        if (l != NULL) flatten(l);
        if (r != NULL) flatten(r);
    }
};
