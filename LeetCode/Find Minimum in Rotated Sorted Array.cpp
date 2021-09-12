class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = (int) nums.size();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[n - 1] > nums[mid]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return nums[hi];
    }
};
