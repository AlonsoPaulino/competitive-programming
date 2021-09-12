const int MOD = 1e9 + 7;
typedef long long ll;

class Solution {
public:
    int sum(int a, int b) {
        return (a % MOD + b % MOD) % MOD;
    }
    
    int numWays(int steps, int arrLen) {
        int sz = min(steps, arrLen);
        vector<vector<int>> dp(steps + 5, vector<int>(sz + 5, 0));
        dp[1][1] = 1, dp[1][2] = 1;
        
        for (int i = 2; i <= steps; ++i) {
            for (int j = 1; j <= sz; ++j) {
                int left = dp[i - 1][j - 1];
                int stay = dp[i - 1][j];
                int right = dp[i - 1][j + 1];
                dp[i][j] = sum(left, sum(stay, right));
            }
        }

        return dp[steps][1];
    }
};
