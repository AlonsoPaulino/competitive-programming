class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = (int) nums.size();
        int i = 0, ans = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[j + 1] > nums[j]) ++j;
            int len = j - i + 1;
            ans = max(ans, len);
            i = j + 1;
        }
        return ans;
    }
};

// Another solution written on 09/08/2021
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i = 0, n = (int) nums.size();
        int ans = 1;
        while (i < n) {
            int j = i + 1;
            while (j < n && nums[j] > nums[j - 1]) ++j;
            ans = max(ans, j - i);
            i = j;
        }
        return ans;
    }
};
