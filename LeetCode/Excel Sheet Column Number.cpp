class Solution {
public:
    int titleToNumber(string s) {
        int n = (int) s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = s[n - 1 - i] - 'A' + 1;
            ans += pow(26, i) * x;
        }
        return ans;
    }
};