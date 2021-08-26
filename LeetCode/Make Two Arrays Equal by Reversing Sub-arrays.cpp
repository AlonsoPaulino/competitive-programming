class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = (int) target.size();
        int m = (int) arr.size();
        if (n != m) {
            return false;
        }
        unordered_map<int, int> t;
        for (auto x: target) t[x]++;
        for (auto x: arr) {
            auto it = t.find(x);
            if (it != t.end() && t[x] > 0) {
                t[x] = t[x] - 1;
            } else {
                return false;
            }
        }
        return true;
    }
};
