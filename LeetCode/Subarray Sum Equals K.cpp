class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int > m;
        int ans = 0, sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            ans += m[sum - k];
            if (sum == k) ans++;
            m[sum]++;
        }
        
        return ans;
    }
};