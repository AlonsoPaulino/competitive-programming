class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] != nums[i - 1]) break;
            else i += 2;
        }
        return nums[i - 1];
    }
};