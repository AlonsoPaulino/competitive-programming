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
    bool solve(TreeNode* root, long lo, long hi) {
        if (root == NULL) return true;
        
        bool left = solve(root->left, lo, (long) root->val - 1L);
        bool right = solve(root->right, (long) root->val + 1L, hi);
        
        return left && right && root->val >= lo && root->val <= hi;
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root, (long) INT_MIN, (long) INT_MAX);
    }
};

// Solution written on 09/07/2021
typedef long long ll;

class Solution {
public:
    bool dfs(TreeNode* root, ll lo, ll hi) {
        if (root == NULL) return true;
        bool left = dfs(root->left, lo, root->val - 1LL);
        bool right = dfs(root->right, root->val + 1LL, hi);
        bool curr = root->val >= lo && root->val <= hi;
        return left && right && curr;
    }
    
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
