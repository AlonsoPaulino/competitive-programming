class Solution {
public:
    static bool compare(pair<int, int> p1, pair<int, int> p2) {
        if (p1.second < p2.second) return true;
        else if (p1.second == p2.second) return p1.first < p2.first;
        return false;
    }
    
    int pw(int x) {
        int steps = 0;
        while (x != 1) {
            if (x & 1) {
                x = 3 * x + 1;
            } else {
                x /= 2;
            }
            ++steps;
        }
        return steps;
    }
    
    int getKth(int lo, int hi, int k) {
        vector< pair<int, int> > v;
        for (int i = lo; i <= hi; ++i) {
            v.push_back(make_pair(i, pw(i)));
        }
        sort(v.begin(), v.end(), compare);
        return v[k - 1].first;
    }
};