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
    int cnt = 0;
public:
    void solve(TreeNode* root, int x) {
        cout << "root -> val : " << root -> val << "  x : " << x << endl;
        if (root->val >= x) cnt++;
        if (root->left != NULL) {
            solve(root->left, max(x, root->val));
        }
        if (root->right != NULL) {
            solve(root->right, max(x, root->val));
        }
    }
    
    int goodNodes(TreeNode* root) {
        solve(root, root->val);
        return cnt;
    }
};

// Another solution written on 08/17/2021
class Solution {
    int ans = 0;
public:
    void solve(TreeNode* root, int hi) {
        if (root == NULL) return;
        if (root->val >= hi) ++ans;
        solve(root->left, max(root->val, hi));
        solve(root->right, max(root->val, hi));
    }
    
    int goodNodes(TreeNode* root) {
        if (root != NULL) {
            solve(root, root->val);
        }
        return ans;
    }
};
