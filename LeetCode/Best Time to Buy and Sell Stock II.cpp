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

// Another solution written on 09/10/2021
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i = 0, n = (int) prices.size();
        while (i < n) {
            int j = i + 1;
            while (j < n && prices[j] <= prices[j - 1]) ++j;
            if (j < n) {
                int buy = prices[j - 1];
                while (j < n && prices[j] >= prices[j - 1]) ++j;
                if (j <= n) {
                    int sell = prices[j - 1];
                    profit += (sell - buy);
                }
            }
            i = j;
        }
        return profit;
    }
};
