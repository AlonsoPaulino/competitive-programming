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
    vector<int> v;

    TreeNode* subTree(int i, int j) {
        if (i >= j) return NULL;
        TreeNode* root = new TreeNode(v[i]);
        int l = i + 1, r;
        for (r = l; r < j; ++r) {
            if (v[r] > root->val) break;
        }
        root->left = subTree(l, r);
        root->right = subTree(r, j);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        v = preorder;
        return subTree(0, (int) preorder.size());
    }
};