class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); int m = n > 0 ? grid[0].size() : 0;
        if (n == 0 && m == 0) return 0;
        vector< vector<int> > dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];   
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};