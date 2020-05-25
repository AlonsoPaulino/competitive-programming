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
// NOTE : This is the code I wrote the last time I submitted this problem and got AC :)
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // This is the code I wrote the very first time I had to deal with this problem :)
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