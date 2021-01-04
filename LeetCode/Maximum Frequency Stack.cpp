class FreqStack {
    map<int, vector<int>> m;
    unordered_map<int, int> f;
public:
    FreqStack() { 
        
    }
    
    void push(int x) {
        int y = ++f[x];
        m[y].push_back(x);
    }
    
    int pop() {
        auto it = m.rbegin();    
        int key = it->first;
        vector<int> v = it->second;
        int n = (int) v.size();
        
        int num = v[n - 1]; v.pop_back();
        f[num]--;
        
        if ((int) v.size() == 0) {
            m.erase(key);
        } else {
            m[key] = v;
        }
        
        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */