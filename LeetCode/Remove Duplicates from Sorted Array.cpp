class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, n = (int) nums.size();
        if (n == 0) {
            return 0;
        }
        while (j < n) {
            while (j < n && nums[j] == nums[i]) ++j;
            if (j < n) {
                nums[i + 1] = nums[j];
                ++i, ++j;
            }
        }
        return i + 1;
    }
};
