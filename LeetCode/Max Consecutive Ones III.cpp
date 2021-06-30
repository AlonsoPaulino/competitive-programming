class Solution {
public:    
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = 0, hi, ans = 0, cnt = 0;
        for (hi = 0; hi < n; ++hi) {
            if (nums[hi] == 0) cnt++;
            if (cnt > k) {
                if (nums[lo] == 0) cnt--;
                ++lo;
            }
        }
        return hi - lo;
    }
};
