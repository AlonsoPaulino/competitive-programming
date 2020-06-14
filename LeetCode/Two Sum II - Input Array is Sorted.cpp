class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = (int) numbers.size();
        vector<int> ans(2, 0);
        for (int i = 0; i < n; ++i) {
            int x = numbers[i];
            int y = target - numbers[i];
            int k = lower_bound(numbers.begin() + i + 1, numbers.end(), y) - numbers.begin();
            if (k != i && numbers[k] == y) {
                ans[0] = i + 1, ans[1] = k + 1;
                break;
            }
        }
        return ans;
    }
};