class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (m > 0 && nums[m] == nums[m - 1]) {
                int x = m - 1 - l;
                if (x & 1) {
                    r = m - 2;
                } else {
                    l = m + 1;
                }
            } else if (m < nums.size() - 1 && nums[m] == nums[m + 1] ){
                int x = r - m - 1;
                if (x & 1) {
                    l = m + 2;
                } else {
                    r = m - 1;
                }
            } else return nums[m];
        }
        return -1;
    }
};