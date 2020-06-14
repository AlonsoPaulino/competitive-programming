class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            m[nums[i]] = i;
        }
        vector<int> ans(2, 0);
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            int y = target - x;
            if (m.find(y) != m.end() && i != m[y]) {
                ans[0] = i;
                ans[1] = m[y];
                break;
            }
        }
        return ans;
    }
};