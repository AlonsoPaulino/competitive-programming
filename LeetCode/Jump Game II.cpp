class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> dp(n, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i + j < n && j <= nums[i]; ++j) {
                int x = i + j;
                if (dp[x] == 0) dp[x] = dp[i] + 1;
                else dp[x] = min(dp[x], dp[i] + 1);
            }
        }
        
        return dp[n - 1];
    }
};
