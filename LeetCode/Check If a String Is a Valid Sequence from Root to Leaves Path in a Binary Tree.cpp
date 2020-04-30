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
    bool isValid(TreeNode* node, vector<int>&arr, int position) {
        if (node == NULL) return false;
        if (arr[position] != node->val) return false;
        if (position + 1 == arr.size()) 
            return node->left == NULL && node-> right == NULL;
        return isValid(node->left, arr, position + 1) || isValid(node->right, arr, position + 1);
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (root == NULL || arr.size() == 0) return false;
        return isValid(root, arr, 0);
    }
};