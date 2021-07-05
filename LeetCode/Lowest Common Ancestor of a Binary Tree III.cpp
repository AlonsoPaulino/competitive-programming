/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    set<int> st;
public:    
    Node* lowestCommonAncestor(Node* p, Node * q) {
        while (p != NULL) {
            st.insert(p->val);
            p = p->parent;
        }
        while (q != NULL) {
            if (st.find(q->val) != st.end()) {
                return q;
            }
            q = q->parent;
        }
        return NULL;
    }
};
