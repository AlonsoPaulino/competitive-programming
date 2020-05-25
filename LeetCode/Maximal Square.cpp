class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = (int) matrix.size();
        int m = n == 0 ? 0 : (int) matrix[0].size();
        vector<vector<int>> dp(n + 5, vector<int>(m + 5, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (matrix[i - 1][j - 1] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};