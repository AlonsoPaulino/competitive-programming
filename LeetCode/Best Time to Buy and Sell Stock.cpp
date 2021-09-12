class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int) prices.size();
        if (n == 0) {
            return 0;
        }
        int p = prices[n - 1];
        int ans = 0;
        
        for (int i = n - 2; i >= 0; --i) {
            if (p > prices[i]) {
                ans = max(ans, p - prices[i]);
            }
            p = max(p, prices[i]);
        }
        
        return ans;
    }
};
