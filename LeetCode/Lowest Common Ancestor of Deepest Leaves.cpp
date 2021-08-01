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
const int N = 1005;

class Solution {
public:
    map<TreeNode*, TreeNode*> p;
    map<int, vector<TreeNode*>> d;
    
    void dfs(TreeNode* parent, TreeNode* x, int depth) {
        if (x == NULL) return;
        p[x] = parent;
        d[depth].push_back(x);
        dfs(x, x->left, depth + 1);
        dfs(x, x->right, depth + 1);
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == NULL) return NULL;
        dfs(NULL, root, 0);
        auto v = (--d.end())->second;
        set<TreeNode*> st;
        for (auto x: v) st.insert(x);
        while ((int) st.size() > 1) {
            vector<TreeNode*> tmp;
            for (auto it: st) {
                tmp.push_back(p[it]);
            }
            st.clear();
            for (auto x: tmp) {
                st.insert(x);
            }
        }
        return *st.begin();
    }
};
