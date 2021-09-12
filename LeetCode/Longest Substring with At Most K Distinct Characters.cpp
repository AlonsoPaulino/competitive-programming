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

// Another solution written on 09/06/2021
class Solution {
public:    
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> um;
        int i = 0, j = 0, n = (int) s.size();
        int ans = 0;
        while (j < n) {
            ++um[s[j]];
            while (i <= j && um.size() > k) {
                --um[s[i]];
                if (um[s[i]] == 0) um.erase(s[i]);
                ++i;
            }
            if (i <= j) {
                ans = max(ans, j - i + 1);
            }
            ++j;
        }
        return ans;
    }
};
