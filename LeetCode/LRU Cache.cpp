class LRUCache {
public:
    int n;
    list<pair<int, int>> v;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            auto& it = m[key];
            pair<int, int> value = *it;
            v.erase(it);
            v.push_back(value);
            m[key] = --v.end();
            return value.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        int x = (int) v.size();
        if (m.find(key) != m.end()) {
            auto& it = m[key];
            v.erase(it);
            v.push_back({key, value});
            m[key] = --v.end();
            return;
        }
        if (x + 1 > n) {
            pair<int, int> aux = v.front();
            m.erase(aux.first);
            v.erase(v.begin());
        }
        v.push_back({key, value});
        m[key] = --v.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */