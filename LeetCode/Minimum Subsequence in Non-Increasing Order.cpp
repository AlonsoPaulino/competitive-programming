class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size(), sum = 0, tmp = nums[0], x = 0;
        for (int i = 0; i < n; ++i) sum += nums[i];
        for (int i = 1; i < n && tmp < (sum - tmp); ++i) {
            tmp += nums[i];
            x = i;
        }
        for (int i = n - 1; i >= x; --i) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};