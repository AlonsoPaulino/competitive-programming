class Solution {
    vector<int> dp;
public:
    int solve(int x) {
        if (dp[x] != -1) return dp[x];
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (x % 2 == 0) {
            return solve(x / 2);
        }
        return solve((x - 1) / 2) + solve((x - 1) / 2 + 1);
    }
    
    int getMaximumGenerated(int n) {
        dp = vector<int>(n + 5, -1);
        int a = 0;
        for (int i = 1; i <= n; ++i) {
            a = max(a, solve(i));
        }
        return a;
    }
};