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