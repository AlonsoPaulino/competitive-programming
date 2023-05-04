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
    int h, w;
    
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    
    void populate(TreeNode* root, vector<vector<string>> &v, int x, int y) {
        v[x][y] = to_string(root->val);
        if (root->left != NULL) {
            populate(root->left, v, x + 1, y - (1 << (h - 1 - x - 1)));
        }
        if (root->right != NULL) {
            populate(root->right, v, x + 1, y + (1 << (h - 1 - x - 1)));   
        }
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        h = depth(root);
        w = (1 << h) - 1;
        vector<vector<string>> v(h, vector<string>(w));
        populate(root, v, 0, (w - 1) / 2);
        return v;
    }
};
