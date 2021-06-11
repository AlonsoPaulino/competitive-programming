typedef pair<int, int> pii;

class MyCalendar {
    vector<pii> v;
public:
    MyCalendar() {
        // Do nothing    
    }
    
    bool book(int start, int end) {
        for (auto p: v) {
            if (intersect(p, {start, end - 1})) {
                return false;
            }
        }
        v.push_back({start, end - 1});
        return true;
    }
    
    bool intersect(pii a, pii b) {
        return a.second >= b.first && a.first <= b.second;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
