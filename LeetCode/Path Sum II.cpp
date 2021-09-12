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
    bool isLeaf(TreeNode* x) {
        return x->left == NULL && x->right == NULL;
    }
    
    vector<vector<int>> ans;
    
    void dfs(TreeNode* x, vector<int> v, int sum, int target) {
        if (x == NULL) return;
        v.push_back(x->val);
        if (isLeaf(x) && sum + x->val == target) {
            ans.push_back(v);
            return;
        }
        dfs(x->left, v, sum + x->val, target);
        dfs(x->right, v, sum + x->val, target);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return vector<vector<int>>();
        ans = vector<vector<int>>();
        dfs(root, vector<int>(), 0, targetSum);
        return ans;
    }
};
