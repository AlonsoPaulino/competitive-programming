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
    map<int, int> cnt;
    int max_depth = 0;
    TreeNode* ans = NULL;
public:
    void calc_max_depth(TreeNode* root, int d) {
        if (root == NULL) return;
        calc_max_depth(root->left, d + 1);
        calc_max_depth(root->right, d + 1);
        cnt[d]++;
        max_depth = max(max_depth, d);
    }
    
    int solve(TreeNode* root, int d) {
        if (root == NULL) return 0;
        int a = solve(root->left, d + 1);
        int b = solve(root->right, d + 1);
        int total = a + b + (d == max_depth ? 1 : 0);
        
        if (ans == NULL && total == cnt[max_depth]) {
            ans = root;
        }
        
        return total;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        calc_max_depth(root, 0);
        solve(root, 0);
        return ans;
    }
};
