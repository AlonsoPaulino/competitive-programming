class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = (int) costs.size();
        int dp[n/2 + 5][n/2 + 5];
        memset(dp, 0, sizeof(dp));
        
        for (int x = 0; x <= n/2; ++x) {
            for (int y = 0; y <= n/2; ++y) {
                if (x != 0 || y != 0) {
                    int i = x + y - 1;
                    if (x == 0) {
                        dp[x][y] = dp[x][y - 1] + costs[i][1];
                    } else if (y == 0) {
                        dp[x][y] = dp[x - 1][y] + costs[i][0];
                    } else {
                        dp[x][y] = min(dp[x - 1][y] + costs[i][0], dp[x][y - 1] + costs[i][1]);
                    }
                }
            }
        }
        
        return dp[n/2][n/2];
    }
};