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
    unordered_map<int, int> mem;
    
    Node* findRoot(vector<Node*> tree) {
        int n = (int) tree.size();
        for (auto it: tree) {
            int total = dfs(it);
            if (total == n) {
                return it;
            }
        }
        return NULL;
    }
    
    int dfs(Node* node) {
        if (node == NULL) return 0;
        auto it = mem.find(node->val);
        
        if (it != mem.end()) {
            return it->second;
        }
        
        int total = 0;
        
        for (auto v: node->children) {
            total += dfs(v);
        }
        
        mem[node->val] = total + 1;
        
        return total + 1;
    }
};
