class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ans = 0, cnt = 0, i = 0, n = (int) s.size();
        while (i < n) {
            char c = s[i];
            if (m.find(c) == m.end()) ++cnt, m[c] = i, ++i;
            else i = m[c] + 1, m.clear(), cnt = 0;
            ans = max(ans, cnt);
        }
        return ans;
    }
};