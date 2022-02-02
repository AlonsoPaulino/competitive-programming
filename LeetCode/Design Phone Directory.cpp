class PhoneDirectory {
public:
    unordered_map<int, int> um;
    
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            um[i] = 1;
        }
    }
    
    int get() {
        if (!um.empty()) {
            int x = um.begin()->first;
            um.erase(x);
            return x;
        }
        return -1;
    }
    
    bool check(int number) {
        return (um.find(number) != um.end());
    }
    
    void release(int number) {
        um[number] = 1;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
