class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = (int) nums.size();
        int i = 0, ans = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[j + 1] > nums[j]) ++j;
            int len = j - i + 1;
            ans = max(ans, len);
            i = j + 1;
        }
        return ans;
    }
};
