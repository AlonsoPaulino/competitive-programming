class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        int i = 0;
        vector<vector<int>> ans;
        while (i + 2 < n) {
            int a = nums[i++];
            int j = i;
            while (i + 2 < n && nums[i] == a) ++i;
            while (j + 1 < n) {
                int b = nums[j++];
                int k = lower_bound(nums.begin() + j, nums.end(), -(a + b)) - nums.begin();
                if (k < n && a + b + nums[k] == 0) {
                    ans.push_back({a, b, nums[k]});
                }
                while (j + 1 < n && nums[j] == b) ++j;
            }
        }
        return ans;
    }
};