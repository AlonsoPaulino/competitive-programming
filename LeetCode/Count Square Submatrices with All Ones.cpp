class Solution {
public:
    int countSquares(vector<vector<int>>& dp) {
        int n = (int) dp.size();
        int m = (int) dp[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dp[i][j] == 0) continue;
                if (i == 0 || j == 0) {
                    ans += dp[i][j];
                    continue;
                }
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                ans += dp[i][j];
            }
            endl(cout);
        }
        return ans;
    }
};
