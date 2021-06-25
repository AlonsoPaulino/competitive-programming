const int MAX = 50;
const int MOD = 1e9 + 7;

const int di[4] = { 0, 0, 1, -1 };
const int dj[4] = { 1, -1, 0, 0 };

class Solution {
    int dp[MAX][MAX][MAX];
    int r = 0, c = 0;
public:
    int sum(int a, int b) {
        return (a % MOD + b % MOD) % MOD;
    }
    
    int is_valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    
    void solve(int i, int j, int moves) {
        for (int i = 0; i < MAX; ++i) {
            for (int j = 0; j < MAX; ++j) {
                if (dp[i][j][moves - 1] > 0) {
                    for (int k = 0; k < 4; ++k) {
                        int ii = i + di[k], jj = j + dj[k];
                        if (is_valid(ii, jj)) {
                            dp[ii][jj][moves] = 
                                sum(dp[ii][jj][moves], dp[i][j][moves - 1]);
                        }
                    }
                }
            }
        }
    }
    
    int findPaths(int m, int n, int max_move, int x, int y) {
        fill_n(&dp[0][0][0], sizeof(dp) / sizeof(dp[0][0][0]), 0);
        r = m, c = n;
        
        dp[x][y][0] = 1;
        
        for (int m = 1; m < max_move; ++m) {
            solve(x, y, m);
        }
        
        int ans = 0;
        
        for (int i = 0; i < r; ++i) {
            for (int m = 0; m < max_move; ++m) {
                ans = sum(ans, dp[i][0][m]);
                ans = sum(ans, dp[i][c - 1][m]);
            }
        }
        
        for (int j = 0; j < c; ++j) {
            for (int m = 0; m < max_move; ++m) {
                ans = sum(ans, dp[0][j][m]);
                ans = sum(ans, dp[r - 1][j][m]);
            }
        }
        
        return ans;
    }
};
