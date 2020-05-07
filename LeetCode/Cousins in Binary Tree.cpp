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
    bool isCousins(TreeNode* root, int x, int y) {
        queue< pair<TreeNode*,int> > q;
        q.push({root, 0});
        int lx = -1, ly = -1;
        while (!q.empty()) {
            if (lx != -1 && ly != -1) break;
            pair<TreeNode*, int> p = q.front(); q.pop();
            if (p.first->val == x) {
                lx = p.second;
            }
            if (p.first->val == y) {
                ly = p.second;
            }
            if (p.first->left != NULL) q.push({p.first->left, p.second + 1});
            if (p.first->right != NULL) q.push({p.first->right, p.second + 1});
        }
        return lx == ly;
    }
};