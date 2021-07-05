class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = (int) s.size();
        int window = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < n; ++i) {
            m[s[i]]++;
            if (m.size() <= k) {
                ++window;
            } else {
                m[s[i - window]]--;
                if (m[s[i - window]] == 0) m.erase(s[i - window]);
            }
        }
        return window;
    }
};
