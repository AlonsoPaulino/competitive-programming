class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (k >= i) {
                k = max(k, i + nums[i]);   
            } else {
                break;
            }
        }
        return k >= (nums.size() - 1);
    }
};