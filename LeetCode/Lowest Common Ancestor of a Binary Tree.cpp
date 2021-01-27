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
