class BrowserHistory {
public:
    stack<string> h;
    stack<string> fw;
    
    BrowserHistory(string homepage) {
        h.push(homepage);
    }
    
    void visit(string url) {
        while (!fw.empty()) fw.pop();
        h.push(url);
    }
    
    string back(int steps) {
        string x = h.top();
        while (steps > 0 && h.size() > 1) {
            fw.push(x);
            h.pop();
            x = h.top();
            --steps;
        }
        return x;
    }
    
    string forward(int steps) {
        string x = h.top();
        while (steps > 0 && !fw.empty()) {
            x = fw.top();
            h.push(x);
            fw.pop();
            --steps;
        }
        return x;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */