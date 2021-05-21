class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = (int) nums.size(), sum = 0;
        sort(nums.begin(), nums.end());
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            a += abs(nums[i] - nums[n / 2]);
            if (n % 2 == 0) b += abs(nums[i] - nums[n / 2 - 1]);
        }
        return b == 0 ? a : min(a, b);
    }
};
