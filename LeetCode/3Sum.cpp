class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        int i = 0;
        vector<vector<int>> ans;
        while (i + 2 < n && nums[i] <= 0) {
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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int) nums.size();
        unordered_map<int, int> mnums;
        map<pair<int, int>, bool> mpairs;
        vector<vector<int>> ans;
        for (auto x: nums) mnums[x]++;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = nums[i], b = nums[j], c = -1 * (a + b);
                int cnt = 0;
                if (a == c) cnt++;
                if (b == c) cnt++;
                if (mnums[c] > cnt) {
                    vector<int> aux = {a, b, c};
                    int x = min(a, min(b, c)), y = max(a, max(b, c));
                    pair<int, int> pp = { x, y };
                    if (!mpairs[pp]) {
                        mpairs[pp] = 1;
                        ans.push_back(aux);
                    }
                }
            }
        }
        return ans;
    }
};