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