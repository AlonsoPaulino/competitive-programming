class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 0) return 0;
    
        int ans = 1;
        int i = 1, dir = 0;
        
        while (i < n) {
            int diff = nums[i] - nums[i - 1];
            if (diff < 0 && dir >= 0) {
                while (i + 1 < n && nums[i + 1] < nums[i]) ++i;
                dir = -1;
                ++ans;
            } else if (diff > 0 && dir <= 0) {
                while (i + 1 < n && nums[i + 1] > nums[i]) ++i;
                ++ans;
                dir = 1;
            }
            ++i;
        }
        
        return ans;
    }
};
