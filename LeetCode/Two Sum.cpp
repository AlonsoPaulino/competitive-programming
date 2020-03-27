class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i + 1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int d = target - nums[i];
            if (m[d] && ((m[d] - 1) != i)) {
                ans[0] = i;
                ans[1] = m[d] - 1;
                break;
            }
        }
        return ans;
    }
};