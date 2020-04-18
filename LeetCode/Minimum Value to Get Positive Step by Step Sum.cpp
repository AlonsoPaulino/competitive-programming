class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int acum = nums[0];
        int x = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            acum += nums[i];
            x = min(x, acum);
        }
        if (x > 0) return 1;
        else return abs(x) + 1;
    }
};