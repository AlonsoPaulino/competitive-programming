class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int) nums.size(), ans = n * (n + 1) / 2;
        for (auto x: nums) ans = ans - x;
        return ans;
    }
};
