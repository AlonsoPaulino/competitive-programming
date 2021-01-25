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
    vector<int> v;
public:
    TreeNode* balanceBST(TreeNode* root) {
        in_order(root);
        int n = (int) v.size();
        
        return solve(0, n - 1);
    }
    
    void in_order(TreeNode* root) {
        if (root == NULL) return;
        
        in_order(root->left);
        v.push_back(root->val);
        in_order(root->right);
    }
    
    TreeNode* solve(int lo, int hi) {
        if (lo > hi) return NULL;
        
        int mid = lo + (hi - lo) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        
        root->left = solve(lo, mid - 1);
        root->right = solve(mid + 1, hi);
        
        return root;
    }
};
