class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = (int) s.size(), m = (int) t.size();
        int diff = abs(n - m);
        if (diff > 1) return false;
        int cnt = 0, i = 0, j = 0;
        while (i < n) {
            if (s[i] == t[j]) {
                ++i, ++j; continue;
            }
            if (n < m) {
                ++j, ++cnt;
            } else if (n > m) {
                ++i, ++cnt;
            } else {
                ++i, ++j, ++cnt;
            }
            if (cnt > 1) return false;
        }
        if (n == m) {
            return cnt == 1;
        }
        return true;
    }
};
