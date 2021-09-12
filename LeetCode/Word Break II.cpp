class Solution {
public:
    unordered_map<string, bool> m;
    unordered_map<int, bool> dp;
    unordered_map<int, vector<int>> v; 
    
    vector<string> wordBreak(string s, vector<string>& dict) {
        int n = (int) s.size();
        for (auto w: dict) m[w] = true;
        bool is_possible = f(s, 0, n);
        vector<string> ans;
        if (is_possible) {
            queue<pair<int, string>> q;
            q.push({0, ""});
            while (!q.empty()) {
                auto p = q.front(); q.pop();
                int i = p.first;
                string x = p.second;
                if (i == n) {
                    ans.push_back(x);
                    continue;
                }
                for (auto u: v[i]) {
                    string tmp = x;
                    if (tmp.size() != 0) tmp += " ";
                    tmp += s.substr(i, u - i);
                    q.push({u, tmp});
                }
            }
        }
        return ans;
    }
    
    bool f(string &s, int i, int n) {
        if (i == n) {
            return true;
        }
        auto it = dp.find(i);
        if (it != dp.end()) {
            return it->second;
        }
        
        bool res = false;
        for (int k = 1; i + k <= n; ++k) {
            string tmp = s.substr(i, k);
            if (m.find(tmp) != m.end() && f(s, i + k, n)) {
                v[i].push_back(i + k);
                res = true;
            }
        }
        
        return dp[i] = res;
    }
};
