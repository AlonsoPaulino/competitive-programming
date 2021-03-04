/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {    
public:
    int ans;
    
    int depth(TreeNode* node) {
        if (node == NULL) return 0;
        int rd = depth(node->right);
        int rl = depth(node->left);
        ans = max(ans, rd + rl);
        return max(rl, rd) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        depth(root);
        return ans;
    }
};


// Another solution written in 01/26/2021
class Solution {
    int ans = 0;
public:
    int solve(TreeNode* root) {
        if (root == NULL) return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        ans = max(ans, l + r);
        
        return max(l, r) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
