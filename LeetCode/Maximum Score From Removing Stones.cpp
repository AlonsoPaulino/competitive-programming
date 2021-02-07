class Solution {
public:
    bool check(vector<int>& nums) {
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) nums.push_back(nums[i]);
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            bool asc = true;
            for (int j = 1; j < n; ++j) {
                if (nums[i + j] < a) {
                    asc = false;
                    break;
                }
                a = nums[i + j];
            }
            if (asc) return true;
        }
        return false;
    }
};
