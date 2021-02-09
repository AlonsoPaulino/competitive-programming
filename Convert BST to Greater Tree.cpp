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
    int x = 0;
public: 
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) return NULL;
        
        convertBST(root->right);
        
        x += root->val;
        
        root->val = x;
        
        convertBST(root->left);
        
        return root;
    }
};
