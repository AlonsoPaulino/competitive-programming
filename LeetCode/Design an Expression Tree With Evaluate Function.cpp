/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    Node* left;
    Node* right;
    string x;
};

class PostfixNode: public Node {
    public:
    PostfixNode(Node* ll, Node* rr, string xx) {
        left = ll, right = rr, x = xx;
    }
    
    int evaluate() const {
        int n = (int) x.size();
        if (n == 1) {
            char a = x[0];
            if (a == '+') return left->evaluate() + right->evaluate();
            if (a == '-') return left->evaluate() - right->evaluate();
            if (a == '*') return left->evaluate() * right->evaluate();
            if (a == '/') return left->evaluate() / right->evaluate();
        }
        int num = 0, f = 1;
        for (int i = n - 1; i >= 0; --i) {
            num += f * (x[i] - '0');
            f *= 10;
        }
        return num;
    }
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<Node*> ss;
        int n = (int) postfix.size();
    
        for (int i = 0; i < n; ++i) {
            string x = postfix[i];
            int xs = (int) x.size();
            if (xs == 1 && (x[0] < '0' || x[0] > '9')) {
                Node* a = ss.top(); ss.pop();
                Node* b = ss.top(); ss.pop();
                Node* node = new PostfixNode(b, a, x);
                ss.push(node);
            } else {
                Node* node = new PostfixNode(NULL, NULL, x);
                ss.push(node);
            }
        }
        
        Node* root = ss.top(); ss.pop();
        
        return root;
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */