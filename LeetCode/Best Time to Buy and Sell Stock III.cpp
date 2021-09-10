class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int) prices.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 0);
        int maxp = 0;
        int hi = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxp = max(maxp, hi - prices[i]);
            dp[i] = max(0, maxp);
            hi = max(hi, prices[i]);
        }
        int ans = 0;
        int lo = prices[0];
        maxp = 0;
        for (int i = 1; i < n; ++i) {
            maxp = max(maxp, prices[i] - lo);
            if (i + 1 < n) {
                ans = max(ans, maxp + dp[i + 1]);
            } else {
                ans = max(ans, maxp);
            }
            lo = min(lo, prices[i]);
        }
        return max(dp[0], ans);
    }
};
