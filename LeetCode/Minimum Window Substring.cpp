class Solution {
public:
    int to_int(char c) {
        if (c >= 'A' && c <= 'Z') return 26 + c - 'A';
        return c - 'a';
    }
    
    bool same(vector<int> &a, vector<int> &b) {
        for (int i = 0; i < 52; ++i) if (a[i] > b[i]) return false;
        return true;
    }
    
    string minWindow(string s, string t) {
        int ns = (int) s.size(), nt = (int) t.size();
        if (nt > ns) return "";
        vector<int> v(52, 0), m(52, 0);
        for (auto c: t) v[to_int(c)]++;
        int i = 0, j = 0, ans = INT_MAX, k = -1;
        while (j < ns) {
            int x = to_int(s[j]);
            if (v[x] != 0) {
                m[x]++;   
            }
            while (i <= j && same(v, m)) {
                int y = to_int(s[i]);
                if (j - i + 1 < ans) {
                    ans = j - i + 1;
                    k = i;
                }
                m[y] = max(m[y] - 1, 0), ++i;
            }
            ++j;
        }
        if (k == -1) {
            return "";
        }
        return s.substr(k, ans);
    }
};
