class Solution {
public:
    vector<int> z_function(string s) {
        int l = 0, r = 0, k;
        int n = (int) s.size();
        vector<int> z(n);
        z[0] = 0;

        for (int i = 1; i < n; ++i) {
            if (i > r) {
                l = r = i;
                while (r < n && s[r - l] == s[r]) {
                    ++r;
                }
                z[i] = r - l;
                --r;
            } else {
                k = i - l;
                if (z[k] < r - i + 1) {
                    z[i] = z[k];
                } else {
                    l = i;
                    while (r < n && s[r - l] == s[r]) {
                        ++r;
                    }
                    z[i] = r - l;
                    --r;
                }
            }
        }

        return z;
    }
    
    string addBoldTag(string s, vector<string>& dict) {
        vector<pair<int, int>> v;
        vector<pair<int, int>> fv;
        
        int ss = (int) s.size();
        
        for (auto p: dict) {
            vector<int> z = z_function(p + "$" + s);
            int sz = (int) z.size(), sp = (int) p.size();
            for (int i = sp + 1; i < sz; ++i) {
                if (z[i] == sp) {
                    int k = i - sp - 1;
                    v.push_back({k, k + sp - 1});
                }
            }
        }
        
        sort(v.begin(), v.end(), [](pair<int, int> const a, pair<int, int> const b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        
        int lo = -1, hi = -1;
        for (auto x: v) {
            if (lo == -1 && hi == -1) {
                lo = x.first, hi = x.second;
            } else if (x.first > hi + 1) {
                fv.push_back({lo, hi});
                lo = x.first, hi = x.second;
            } else {
                hi = max(x.second, hi);
            }
        }
        if (lo != -1 && hi != -1) {
            fv.push_back({lo, hi});
        }
        
        string ans;
        
        int i = 0;
        
        for (auto x: fv) {
            if (x.first > i) {
                ans += s.substr(i, x.first - i);
            }
            ans += "<b>";
            ans += s.substr(x.first, x.second - x.first + 1);
            ans += "</b>";
            i = x.second + 1;
        }
        
        if (i == -1) {
            return s;
        }
        
        if (i < ss) {
            ans += s.substr(i, ss - i + 1);
        }
        
        return ans;
    }
};