class FirstUnique {
    
    typedef list<int>::iterator liit;
    
    list<int> list;
    unordered_map<int, liit> m;
    
public:
    
    FirstUnique(vector<int>& nums) {
        for (auto &x: nums) {
            add(x);
        }
    }
    
    int showFirstUnique() {
        if (list.size() == 0) return -1;
        return list.front();
    }
    
    void add(int value) {
        if (m.count(value) == 0) {
            list.push_back(value);
            m[value] = --list.end();
        } else {
            if (m[value] != list.end()) {
                list.erase(m[value]);
                m[value] = list.end();   
            }
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */