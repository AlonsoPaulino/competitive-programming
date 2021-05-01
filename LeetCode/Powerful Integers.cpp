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
