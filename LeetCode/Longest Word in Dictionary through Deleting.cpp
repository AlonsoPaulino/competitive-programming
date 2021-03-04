class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        unordered_map<char, vector<int>> m;
        int n = (int) s.size();
        for (int i = 0; i < n; ++i) m[s[i]].push_back(i);
        
        string ans = "";
        
        for (auto x: d) {
            int l = (int) x.size();
            int sz = (int) ans.size();
            int i = 0, j = -1;
            while (i < l && m.find(x[i]) != m.end()) {
                bool found = false;
                for (auto k: m[x[i]]) {
                    if (k > j) {
                        j = k;
                        found = true;
                        break;
                    }
                }
                if (found) {
                    ++i;
                    if (i == l) {
                        if (l > sz || (l == sz && x < ans)) {
                            ans = x;
                            break;
                        }
                    }
                } else break;
            }
        }
        
        return ans;
    }
};
