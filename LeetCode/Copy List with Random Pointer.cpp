/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, int> pos;
        vector<Node*> v;
        
        Node *it = head;
        Node *copy_root = NULL, *prev = NULL;
        
        int k = 0;
        
        while (it != NULL) {
            pos[it] = k++;
            
            Node *node = new Node(it->val);
            if (prev) {
                prev->next = node;
            } else {
                copy_root = node;
            }
            prev = node;
            v.push_back(node);
            
            it = it->next;
        }
        
        it = head, k = 0;
        
        while (it != NULL) {
            if (it->random) {
                v[k]->random = v[pos[it->random]];
            }
            
            ++k;
            it = it->next;
        }
        
        return copy_root;
    }
};
