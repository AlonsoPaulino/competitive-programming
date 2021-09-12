class Solution {
public:
    unordered_map<string, bool> m;
    unordered_map<int, bool> dp;
    
    bool wordBreak(string s, vector<string>& dict) {
        for (auto s: dict) m[s] = true;
        int n = (int) s.size();
        return f(s, 0, n);
    }
    
    bool f(string &s, int i, int n) {
        if (i == n) {
            return true;
        }
        auto it = dp.find(i);
        if (it != dp.end()) {
            return it->second;
        }
        for (int k = 1; i + k <= n; ++k) {
            string x = s.substr(i, k);
            if (m.find(x) != m.end() && f(s, i + k, n)) {
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
};
