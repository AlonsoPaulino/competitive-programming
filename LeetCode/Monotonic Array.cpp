class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = (int) nums.size();
        if (n < 2) return true;
        int dir = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) continue;
            if (nums[i] > nums[i - 1] && dir >= 0) {
                dir = 1; continue;
            }
            if (nums[i] < nums[i - 1] && dir <= 0) {
                dir = -1; continue;
            }
            return false;
        }
        return true;
    }
};
