/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> um;
    
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        queue<Node*> q;
        Node* root = new Node(node->val);
        um[node] = root;
        q.push(node);
        while (!q.empty()) {
            Node* u = q.front(); q.pop();
            for (auto v: u->neighbors) {
                if (um.find(v) == um.end()) {
                    Node* copy = new Node(v->val);
                    um[v] = copy;
                    q.push(v);
                }
                um[u]->neighbors.push_back(um[v]);
            }
        }
        return um[node];
    }
};
