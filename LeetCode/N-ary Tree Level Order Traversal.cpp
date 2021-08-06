/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) return vector<vector<int>>();
        vector<vector<int>> ans;
        queue<pair<Node*, int>> q;
        q.push({ root, 0 });
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int sz = (int) ans.size();
            if (sz > p.second) {
                ans[p.second].push_back(p.first->val);
            } else {
                ans.push_back(vector<int>(1, p.first->val));
            }
            for (auto u: p.first->children) {
                q.push({u, p.second + 1});
            }
        }
        return ans;
    }
};
