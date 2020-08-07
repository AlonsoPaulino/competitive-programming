class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        vector<int> ans;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                ans.push_back(nums[i]); ++i;
            }
        }
        return ans;
    }
};