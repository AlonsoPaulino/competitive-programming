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
class BSTIterator {
public:
    vector<int> v;
    int i = 0;
    int n;
    
    BSTIterator(TreeNode* root) {
        dfs(root);
        n = (int) v.size();
    }
    
    void dfs(TreeNode* node) {
        if (node->left) {
            dfs(node->left);
        }
        v.push_back(node->val);
        if (node->right) {
            dfs(node->right);
        }
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        return i < n;
    }
};

// Another solution written on 08/03/2021
class BSTIterator {
    queue<int> q;
public:
    void dfs(TreeNode* x) {
        if (x == NULL) return;
        dfs(x->left);
        q.push(x->val);
        dfs(x->right);
    }
    
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        int x = q.front(); q.pop();
        return x;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

// Another solution written on 08/05/2021
class BSTIterator {
    queue<int> q;
public:
    void dfs(TreeNode* x) {
        if (x == NULL) return;
        dfs(x->left);
        q.push(x->val);
        dfs(x->right);
    }
    
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};


