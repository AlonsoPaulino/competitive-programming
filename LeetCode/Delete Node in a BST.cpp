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
    TreeNode *tree, *node, *parent;
    int x;
    bool found;
public:
    void findNode() {
        while (!found && node != NULL) {
            if (node->val == x) {
                found = true;
                continue;
            }
            parent = node;
            node = x > node->val ? node->right : node->left;
        }
    }
    
    void delNode() {
        if (!found) return;
        TreeNode *l = node->left, *r = node->right;
        if (l == NULL && r != NULL) {
            node->val = r->val;
            node->left = r->left, node->right = r->right;
        } else if (r == NULL && l != NULL) {
            node->val = l->val;
            node->left = l->left, node->right = l->right;
        } else if (r == NULL && l == NULL) {
            if (parent == NULL) tree = NULL;
            else {
                if (node->val < parent->val) parent->left = NULL;
                else parent->right = NULL;
            }
        } else {
            node->val = r->val;
            node->right = r->right;
            node->left = r->left;
            int u = l->val;
            TreeNode *aux = node;
            while (true) {
                if (u > aux->val) {
                    if (aux->right == NULL) {
                        aux->right = l;
                        break;
                    } else aux = aux->right;
                } else {
                    if (aux->left == NULL) {
                        aux->left = l;
                        break;
                    } else aux = aux->left;
                }
            }
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        x = key, found = false;
        parent = NULL, tree = root, node = root;
        findNode();
        delNode();
        return tree;
    }
};