class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int l = 0, r = 0, n = (int) s.size();
        for (auto& x: shift) if (x[0] == 0) l+=x[1]; else r += x[1];
        int diff = abs(r - l) % n;
        cout << diff << endl;
        if (r > l) {
            return s.substr(n - diff) + s.substr(0, n - diff);
        } else {
            return s.substr(diff) + s.substr(0, diff);
        }
    }
};