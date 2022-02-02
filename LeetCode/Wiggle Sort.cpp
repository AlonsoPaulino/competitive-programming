class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = (int) nums.size();
        int dir = 1;
        for (int i = 1; i < n; ++i, dir *= -1) {
            if (dir == 1 && nums[i] >= nums[i - 1]) continue;
            if (dir == -1 && nums[i] <= nums[i - 1]) continue;
            swap(nums[i], nums[i - 1]);
        }
    }
};
