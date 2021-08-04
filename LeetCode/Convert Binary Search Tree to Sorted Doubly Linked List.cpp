/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    Node* front;
    Node* last;
public:
    void dfs(Node* x) {
        if (x == NULL) return;
        dfs(x->left);
        if (front == NULL) front = x;
        if (last != NULL) {
            x->left = last;
            last->right = x;   
        }
        last = x;
        dfs(x->right);
    }
    
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;
        front = NULL, last = NULL;
        dfs(root);
        last->right = front;
        front->left = last;
        return front;
    }
};
