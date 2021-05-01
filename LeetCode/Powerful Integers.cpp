class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        map<int, bool> mx, my;
        mx[1] = 1, my[1] = 1;
        int k = 1, a = 1, b = 1;
        while (true) {
            int ax = a * x, by = b* y;
            if ((ax >= bound || mx.find(ax) != mx.end()) && 
                (by >= bound || my.find(by) != my.end())) break;
            if (ax < bound) {
                mx[ax] = 1;
                a = ax;
            }
            if (by < bound) {
                my[by] = 1;
                b = by;
            }
        }
        vector<int> ans;
        map<int, bool>::iterator it;
        for (int i = 2; i <= bound; ++i) {
            for (it = mx.begin(); it != mx.end() && it->first < i; ++it) {
                if (my.find(i - it->first) != my.end()) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};


// Another approach written on 04/30/2021
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> a, b;
        set<int> ans;
        a.push_back(1), b.push_back(1);
        
        int ax = 1, by = 1;
        while (x > 1 && ax * x < bound) {
            a.push_back(ax * x);
            ax *= x;
        }
        while (y > 1 && by * y < bound) {
            b.push_back(by * y);
            by *= y;
        }
        
        for (int i = 2; i <= bound; ++i) {
            for (int j = 0; j < a.size(); ++j) {
                if (a[j] >= i) break;
                auto it = lower_bound(b.begin(), b.end(), i - a[j]);
                if (it != b.end() && *it == i - a[j]) ans.insert(i);
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};
