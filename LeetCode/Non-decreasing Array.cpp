class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 1) return true;
        int i = 0;
        while (i + 1 < n && nums[i + 1] >= nums[i]) ++i;
        int j = i + 1;
        if (j < n) while (j + 1 < n && nums[j + 1] >= nums[j]) ++j;
        if (j == n) return true;
        if (j + 1 == n) {
            if (i == 0) return true;
            if (i + 1 == j) return true;
            bool a = i + 1 < n ? nums[i - 1] <= nums[i + 1] : false;
            bool b = i + 2 < n ? nums[i] <= nums[i + 2] : false;
            return a || b;
        }
        
        return false;
    }
};
