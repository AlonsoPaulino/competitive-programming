class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(2, -1);
        unordered_map<int, int> m;
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            m[nums[i]]++;
            if (m[nums[i]] > 1) {
                ans[0] = nums[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (m.find(i + 1) == m.end()) {
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
};
