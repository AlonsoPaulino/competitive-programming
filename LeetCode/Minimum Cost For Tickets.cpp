class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int sz = (int) days.size();
        int n = days[sz - 1];
        vector<bool> v(n + 40, false);
        vector<int> dp(n + 40, 0);
        for (auto x: days) v[x] = true;
        for (int i = 1; i <= n + 30; ++i) {
            int x = dp[i - 1] + costs[0];
            if (i >= 7) x = min(x, dp[i - 7] + costs[1]);
            if (i >= 30) x = min(x, dp[i - 30] + costs[2]);
            if (!v[i]) x = min(x, dp[i - 1]);
            dp[i] = x;
        }
        return dp[n + 30];
    }
};