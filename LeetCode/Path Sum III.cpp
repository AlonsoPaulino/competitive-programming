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
    int ans = 0;
    int target;
public:
    void dfs(TreeNode* root, int sum) {
        if (sum == target) ++ans;
        if (root == NULL) return;
        if (root->left != NULL) dfs(root->left, sum + root->left->val);
        if (root->right != NULL) dfs(root->right, sum + root->right->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        target = sum;
        stack<TreeNode*> ss;
        ss.push(root);
        while (!ss.empty()) {
            auto x = ss.top(); ss.pop();
            dfs(x, x->val);
            if (x->left != NULL) ss.push(x->left);
            if (x->right != NULL) ss.push(x->right);
        }
        return ans;
    }
};