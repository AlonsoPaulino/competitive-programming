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

// Another solution written on 09/07/2021
class Solution {
public:
    int cnt = 0;
    int max_depth = -1;
    TreeNode* ans = NULL;
    
    void dfs(TreeNode* x, int d) {
        if (x == NULL) return;
        if (d == max_depth) ++cnt;
        else if (d > max_depth) {
            max_depth = d, cnt = 1;
        }
        dfs(x->left, d + 1);
        dfs(x->right, d + 1);
    }
    
    int solve(TreeNode* x, int d) {
        if (x == NULL) return 0;
        int a = solve(x->left, d + 1);
        int b = solve(x->right, d + 1);
        int c = (d == max_depth) ? 1 : 0;
        int res = a + b + c;
        if (ans == NULL && res == cnt) {
            ans = x;
        }
        return res;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        solve(root, 0);
        return ans;
    }
};
