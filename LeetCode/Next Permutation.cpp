class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int) nums.size();
        int i = n - 2;
        while (i >= 0) {
            if (nums[i] >= nums[i + 1]) {
                --i; continue;
            }
            for (int j = n - 1; j >= i + 1; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums[j], nums[i]);
                    break;
                }
            }
            sort(nums.begin() + i + 1, nums.end());
            break;
        }
        if (i < 0) {
            sort(nums.begin(), nums.end());
        }
    }
};
