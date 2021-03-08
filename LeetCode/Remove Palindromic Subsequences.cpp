class Solution {
public:
    int removePalindromeSub(string s) {
        int n = (int) s.size();
        if (n > 0) {
            for (int i = 0; i < n / 2; ++i) {
                if (s[i] != s[n - i - 1]) return 2;
            }
            return 1;
        }
        return 0;
    }
};
