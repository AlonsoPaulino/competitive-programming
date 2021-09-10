class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> v(n, vector<int>(n, 1));
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (auto it : mines) {
            v[it[0]][it[1]] = 0;
        }
        int cnt, ans = 0;
        for (int i = 0; i < n; ++i) {
            cnt = 0;
            for (int j = 0; j < n; ++j) {
                cnt = (v[i][j] == 1 ? cnt + 1 : 0);
                dp[i][j] = cnt;
            }
            cnt = 0;
            for (int j = n - 1; j >= 0; --j) {
                cnt = (v[i][j] == 1 ? cnt + 1 : 0);
                dp[i][j] = min(dp[i][j], cnt);
            }
        }
        for (int j = 0; j < n; ++j) {
            cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt = (v[i][j] == 1 ? cnt + 1 : 0);
                dp[i][j] = min(dp[i][j], cnt);
            }
            cnt = 0;
            for (int i = n - 1; i >= 0; --i) {
                cnt = (v[i][j] == 1 ? cnt + 1 : 0);
                dp[i][j] = min(dp[i][j], cnt);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
