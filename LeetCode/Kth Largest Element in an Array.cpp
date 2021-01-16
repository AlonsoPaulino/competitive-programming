class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k - 1];
    }
};

// Another solution written in 01/16/2021
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = (int) nums.size();
        
        if (n == 0) return 0;
        
        sort(nums.begin(), nums.end());
        return nums[n - k];
    }
};