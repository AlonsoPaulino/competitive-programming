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
    int n;
public:
    TreeNode* solve(int i, int j) {
        if (i > j) return NULL;
        int x = (i + j) / 2;
        TreeNode *root = new TreeNode(v[x]);
        root->left = solve(i, x - 1);
        root->right = solve(x + 1, j);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        v = nums, n = (int) nums.size();
        return solve(0, n - 1);
    }
};
