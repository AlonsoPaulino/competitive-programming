const int MAX = 50;
const int MOD = 1e9 + 7;

const int di[4] = { 0, 0, 1, -1 };
const int dj[4] = { 1, -1, 0, 0 };

class Solution {
    int dp[MAX][MAX][MAX];
    int r = 0, c = 0, ans = 0;
public:
    int sum(int a, int b) {
        return (a % MOD + b % MOD) % MOD;
    }
    
    int is_valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int findPaths(int m, int n, int max_move, int x, int y) {
        fill_n(&dp[0][0][0], sizeof(dp) / sizeof(dp[0][0][0]), 0);
        r = m, c = n;
        
        dp[x][y][0] = 1;
        
        for (int m = 1; m < max_move; ++m) {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    if (dp[i][j][m - 1] > 0) {
                        for (int k = 0; k < 4; ++k) {
                            int ii = i + di[k], jj = j + dj[k];
                            if (is_valid(ii, jj)) {
                                dp[ii][jj][m] = 
                                    sum(dp[ii][jj][m], dp[i][j][m - 1]);
                            }
                        }
                    }
                }
            }
        }
        
        for (int m = 0; m < max_move; ++m) {
            for (int i = 0; i < r; ++i) {
                ans = sum(ans, dp[i][0][m]);
                ans = sum(ans, dp[i][c - 1][m]);
            }
            for (int j = 0; j < c; ++j) {
                ans = sum(ans, dp[0][j][m]);
                ans = sum(ans, dp[r - 1][j][m]);
            }
        }
        
        return ans;
    }
};
