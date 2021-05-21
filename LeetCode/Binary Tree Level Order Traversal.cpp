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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if (!root) return ans;
        
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            int lvl = u.first;
            TreeNode* node = u.second;
            
            int sz = (int) ans.size();
            if (sz <= lvl) {
                ans.push_back(vector<int>());
            }
            ans[lvl].push_back(node->val);   
            
            if (node->left) {
                q.push({lvl + 1, node->left});
            }
            if (node->right) {
                q.push({lvl + 1, node->right});
            }
        }
        return ans;
    }
};

// Another solution written at 05/20/2021
class Solution {
    vector<vector<int>> ans;
public:
    void bfs(TreeNode* root, int x) {
        if (root == NULL) return;
        int n = (int) ans.size();
        if (n > x) {
            ans[x].push_back(root->val);
        } else {
            ans.push_back(vector<int>(1, root->val));
        }
        bfs(root->left, x + 1);
        bfs(root->right, x + 1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root, 0);
        return ans;
    }
};
