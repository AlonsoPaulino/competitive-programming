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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        invertTree(left), invertTree(right);
        root->left = right;
        root->right = left;
        return root;
    }
};

// Another solution written in 01/26/2021
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        
        TreeNode* x = root;
        TreeNode* aux = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(aux);
        
        return root;
    }
};
