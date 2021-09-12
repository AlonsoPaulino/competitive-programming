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

// Another solution written on 09/05/2021
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int) s.size();
        unordered_map<char, int> m;
        int i = 0, j = 0, ans = 0;
        while (j < n) {
            char c = s[j];
            if (m[c] == 0) {
                m[c]++;
                ans = max(ans, j - i + 1);
                ++j;
            } else {
                while (m[c] > 0) {
                    --m[s[i]], ++i;
                }
            }
        }
        return ans;
    }
};
