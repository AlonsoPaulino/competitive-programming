class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool ans = true;
        int cnt = 0;
        int i = 0;
        while (i < nums.size() && nums[i] == 0) ++i;
        for (int x = i + 1; x < nums.size(); x++) {
            if (nums[x] == 1) {
                if (cnt < k) {
                    ans = false;
                    break;
                } else {
                    cnt = 0;
                }
            } else cnt++;
        }
        return ans;
    }
};