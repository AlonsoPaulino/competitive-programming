class Solution {
public:
    int maxPower(string s) {
        int n = (int) s.size();
        vector<int> v(n, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                v[i] = v[i - 1] + 1;
            } else {
                v[i] = 1;
            }
            ans = max(ans, v[i]);
        }
        return ans;
    }
};