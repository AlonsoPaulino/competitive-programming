class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 1) return 0;
        int x = prices[0];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            while (i < n && prices[i] <= x) {
                x = prices[i];
                ++i;
            }
            int b = i - 1;
            while (i < n && prices[i] >= x) {
                x = prices[i];
                ++i;
            }
            i--;
            if (i < n && b != i) ans += (prices[i] - prices[b]);
        }
        return ans;
    }
};