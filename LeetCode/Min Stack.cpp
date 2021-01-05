class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> v;
    
    MinStack() {
    }
    
    void push(int x) {
        v.push_back(x);
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v[v.size() - 1];
    }
    
    int getMin() {
        int min = v[0];
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] < min) min = v[i];
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/* Another solution written at 01/05/2021 */
class MinStack {
    stack<int> ss;
    map<int, int> m;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        ss.push(x);
        m[x]++;
    }
    
    void pop() {
        int x = ss.top(); ss.pop();
        if (m[x] - 1 == 0) {
            m.erase(x);
        } else m[x] = m[x] - 1;
    }
    
    int top() {
        return ss.top();
    }
    
    int getMin() {
        auto it = m.begin();
        return it->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */