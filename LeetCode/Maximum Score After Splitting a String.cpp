class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int score = 0;
        if (n == 0) return score;
        vector<int> v(n, 0);
        v[0] = (s[0] == '1') ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '1') {
                v[i] = v[i - 1] + 1;
            } else v[i] = v[i - 1];
        }
        for (int i = 1; i < n; ++i) {
            score = max(score, (i - v[i - 1]) + (v[n - 1] - v[i - 1]));
        }
        return score;
    }
};