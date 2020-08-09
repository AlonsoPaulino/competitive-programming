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
    double diff(double a, double b) {
        double x = a - b;
        return x < 0.0 ? -1.0 * x : x;
    }
    
    int closestValue(TreeNode* root, double target) {
        double d = diff(root->val, target); int ans = root->val;
        stack<TreeNode *> ss;
        ss.push(root);
        while (!ss.empty()) {
            auto a = ss.top(); ss.pop();
            double x = diff((double) a->val, target);
            if (x < d) d = x, ans = a->val;
            if (a->left) ss.push(a->left); 
            if (a->right) ss.push(a->right);
        }
        return ans;
    }
};