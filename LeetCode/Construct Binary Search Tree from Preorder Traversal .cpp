/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    
    TreeNode* subtree(int x, int n) {
        if (n - x <= 0) return NULL;
        TreeNode* root = new TreeNode(v[x]);
        if (n - x == 1) return root;
        int k = n;
        for (int i = x + 1; i < n; ++i) {
            if (v[i] > v[x]) {
                k = i;
                break;
            }
        }
        root->left = subtree(x + 1, k);
        root->right = subtree(k, n);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        v = preorder;
        if (preorder.size() == 0) return NULL;
        return subtree(0, v.size());
    }
};