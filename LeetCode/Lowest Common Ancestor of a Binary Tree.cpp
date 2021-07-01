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
    unordered_map<int, pair<TreeNode*, int>> m;
public:
    void dfs(TreeNode* root, TreeNode* parent, int level) {
        if (root == NULL) return;
        m[root->val] = { parent, level };
        dfs(root->left, root, level + 1);
        dfs(root->right, root, level + 1);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        
        dfs(root, root, 0);
        
        int p_level = m[p->val].second;
        int q_level = m[q->val].second;
        
        while (p_level != q_level) {
            if (p_level > q_level) {
                p = m[p->val].first;
                p_level--;
            } else if (p_level < q_level) {
                q = m[q->val].first;
                q_level--;
            }
        }
        while (p->val != q->val) {
            p = m[p->val].first, q = m[q->val].first;
        }
        
        return p;
    }
};

// Another solution written at 07/01/2021
class Solution {
    unordered_map<int, int> depth;
    unordered_map<int, TreeNode*> parent;
public:
    void dfs(TreeNode* p, TreeNode* x, int d) {
        if (x == NULL) return;
        parent[x->val] = p;
        depth[x->val] = d;
        if (x->left) dfs(x, x->left, d + 1);
        if (x->right) dfs(x, x->right, d + 1);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        dfs(root, root, 0);
        TreeNode *x, *y;
        if (depth[p->val] > depth[q->val]) {
            x = p, y = q;
        } else {
            y = p, x = q;
        }
        while (depth[x->val] > depth[y->val]) {
            x = parent[x->val];
        }
        while (x->val != y->val) {
            x = parent[x->val];
            y = parent[y->val];
        }
        return x;
    }
};
