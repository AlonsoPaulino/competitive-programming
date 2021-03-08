class Solution {
public:
    int removePalindromeSub(string s) {
        int n = (int) s.size();
        if (n == 0) return 0;
        else {
            bool pal = true;
            for (int i = 0; pal && i < n / 2; ++i) {
                pal = (s[i] == s[n - i - 1]);
            }
            return pal ? 1 : 2;
        }
    }
};
