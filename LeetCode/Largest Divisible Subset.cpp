class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        int cnt = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            int x = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) x = max(dp[j], x);
            }
            dp[i] = 1 + x;
            cnt = max(cnt, dp[i]);
        }
        vector<int> ans;
        for (int i = n - 1; i >= 0 && cnt > 0; --i) {
            if (dp[i] == cnt) {
                ans.push_back(nums[i]);
                --cnt;
            }
        }
        return ans;
    }
};